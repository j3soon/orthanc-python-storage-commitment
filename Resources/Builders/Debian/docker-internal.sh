#!/bin/bash
set -ex

BUILD_TYPE=$1
PYTHON_VERSION=$2
USER_ID=$3
GROUP_ID=$4

# Create the same user and group than the one who is running the
# "./docker-{distro}-compile.sh" script on the hosting system (*)
groupadd -g ${GROUP_ID} -r orthanc
useradd -u ${USER_ID} -r -g orthanc orthanc

apt-get update
DEBIAN_FRONTEND=noninteractive apt-get -y install nano build-essential unzip cmake pkg-config python libpython3-dev curl
apt-get -y clean
rm -rf /var/lib/apt/lists/*


# On Bullseye, we get "stat: cannot statx
# '/usr/share/mercurial/hgext.rc': Operation not permitted" if
# installing the "mercurial" package using apt-get. As a consequence,
# we manually install Mercurial from sources.
MERCURIAL=mercurial-5.4.1
cd /tmp
curl https://www.mercurial-scm.org/release/${MERCURIAL}.tar.gz > ${MERCURIAL}.tar.gz
tar xvf ${MERCURIAL}.tar.gz
export PATH=${PATH}:/tmp/${MERCURIAL}/


mkdir /tmp/source-writeable

cp -r /source/CMakeLists.txt /tmp/source-writeable/
cp -r /source/Sources /tmp/source-writeable/
cp -r /source/Resources /tmp/source-writeable/

mkdir /tmp/build
cd /tmp/build

cmake /tmp/source-writeable/ \
      -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -DPYTHON_VERSION=${PYTHON_VERSION} \
      -DSTATIC_BUILD=ON \
      -DCMAKE_INSTALL_PREFIX=/target 

make -j`nproc`

if [ "$1" == "Release" ]; then
    strip ./libOrthancPython.so
fi

# Copy the installation to the host filesystem, using the
# newly-created user "orthanc" (*) that corresponds to the user who is
# running "./debian-{distro}-compile.sh" script. This allows to avoid
# files owned by the "root" user on the host filesystem.
su -c "cp /tmp/build/libOrthancPython.so /target" orthanc
