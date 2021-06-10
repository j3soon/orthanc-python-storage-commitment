/**
 * Python plugin for Orthanc
 * Copyright (C) 2020-2021 Osimis S.A., Belgium
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/


#pragma once

#include "PythonHeaderWrapper.h"

#include <boost/noncopyable.hpp>
#include <string>

class ICallbackRegistration : public boost::noncopyable
{
public:
  virtual ~ICallbackRegistration()
  {
  }

  virtual void Register() = 0;

  // The GIL must be locked
  static PyObject *Apply(ICallbackRegistration& registration,
                         PyObject* args,
                         PyObject*& singletonCallback,
                         const std::string& details);

  static void Unregister(PyObject*& singletonCallback);
};
