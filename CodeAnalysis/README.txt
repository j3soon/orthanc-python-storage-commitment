
Introduction
============

This folder contains the Python script that analyzes the header of the
Orthanc Plugin SDK using clang, then automatically wraps this SDK as a
Python extension module. The output of the script is written to
"../Sources/Autogenerated".


Usage on Ubuntu 18.04
=====================

$ sudo apt-get install python-clang-4.0
$ python2 ./ParseOrthancSDK.py --libclang=libclang-4.0.so.1 \
          --source ../Resources/Orthanc/Sdk-1.10.0/orthanc/OrthancCPlugin.h \
          --target ../Sources/Autogenerated


Run through docker
==================

$ docker-compose up --build
