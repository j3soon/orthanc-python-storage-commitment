/**
 * Python plugin for Orthanc
 * Copyright (C) 2017-2020 Osimis S.A., Belgium
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


typedef struct 
{
  PyObject_HEAD

  /* Type-specific fields go here. */
  OrthancPluginDicomInstance* object_;
  bool borrowed_;
} sdk_OrthancPluginDicomInstance_Object;



// Forward declaration of the methods
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceRemoteAet(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSize(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceJson(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSimplifiedJson(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginHasInstanceMetadata(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceMetadata(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceOrigin(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args);


static PyMethodDef sdk_OrthancPluginDicomInstance_Methods[] = {
  { "GetInstanceRemoteAet",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceRemoteAet, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceRemoteAet()" },
  { "GetInstanceSize",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSize, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceSize()" },
  { "GetInstanceJson",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceJson, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceJson()" },
  { "GetInstanceSimplifiedJson",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSimplifiedJson, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceSimplifiedJson()" },
  { "HasInstanceMetadata",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginHasInstanceMetadata, METH_VARARGS,
    "Generated from C function OrthancPluginHasInstanceMetadata()" },
  { "GetInstanceMetadata",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceMetadata, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceMetadata()" },
  { "GetInstanceOrigin",
    (PyCFunction) sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceOrigin, METH_VARARGS,
    "Generated from C function OrthancPluginGetInstanceOrigin()" },
  { NULL }  /* Sentinel */
};


static int sdk_OrthancPluginDicomInstance_Constructor(
  sdk_OrthancPluginDicomInstance_Object *self, PyObject *args, PyObject *kwds)
{
  OrthancPlugins::LogInfo("Creating Python object of class OrthancPluginDicomInstance");

  self->object_ = NULL;
  self->borrowed_ = false;
  
  long long object = 0;
  unsigned char borrowed = false;
  
  if (PyArg_ParseTuple(args, "Lb", &object, &borrowed))
  {
    self->object_ = reinterpret_cast<OrthancPluginDicomInstance*>(static_cast<intptr_t>(object));
    self->borrowed_ = borrowed;
    return 0;
  }
  else
  {
    PyErr_SetString(PyExc_ValueError, "Expected a pair (pointer, borrowed) in the constructor");
    return -1;
  }
}


/**
 * Static global structure => the fields that are beyond the last
 * initialized field are set to zero.
 * https://stackoverflow.com/a/11152199/881731
 **/
static PyTypeObject sdk_OrthancPluginDicomInstance_Type = {
  PyVarObject_HEAD_INIT(NULL, 0)
  "orthanc.DicomInstance",    /* tp_name */
  sizeof(sdk_OrthancPluginDicomInstance_Object), /* tp_basicsize */
};




// Actual implementation of the methods
static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceRemoteAet(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceRemoteAet() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }


  const char* s = OrthancPluginGetInstanceRemoteAet(OrthancPlugins::GetGlobalContext(), self->object_);
  
  if (s == NULL)
  {
    Py_INCREF(Py_None);
    return Py_None;
  }
  else
  {
    return PyUnicode_FromString(s);
  }
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSize(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceSize() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }


  long value = OrthancPluginGetInstanceSize(OrthancPlugins::GetGlobalContext(), self->object_);
  
  return PyLong_FromLong(value);
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceJson(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceJson() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }


  OrthancPlugins::OrthancString s;
  s.Assign(OrthancPluginGetInstanceJson(OrthancPlugins::GetGlobalContext(), self->object_));
  
  if (s.GetContent() == NULL)
  {
    // TODO => RAISE : https://stackoverflow.com/questions/60832317
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_InternalError);
    PyErr_SetString(PyExc_ValueError, "Internal error");
    return NULL;
  }
  else
  {
    return PyUnicode_FromString(s.GetContent());
  }
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceSimplifiedJson(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceSimplifiedJson() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }


  OrthancPlugins::OrthancString s;
  s.Assign(OrthancPluginGetInstanceSimplifiedJson(OrthancPlugins::GetGlobalContext(), self->object_));
  
  if (s.GetContent() == NULL)
  {
    // TODO => RAISE : https://stackoverflow.com/questions/60832317
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_InternalError);
    PyErr_SetString(PyExc_ValueError, "Internal error");
    return NULL;
  }
  else
  {
    return PyUnicode_FromString(s.GetContent());
  }
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginHasInstanceMetadata(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginHasInstanceMetadata() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }

  const char* arg0 = NULL;

  if (!PyArg_ParseTuple(args, "s", &arg0))
  {
    // TODO => RAISE : https://stackoverflow.com/questions/60832317
    PyErr_SetString(PyExc_TypeError, "Bad types for the arguments (1 arguments expected)");
    return NULL;
  }
  long value = OrthancPluginHasInstanceMetadata(OrthancPlugins::GetGlobalContext(), self->object_, arg0);
  
  return PyLong_FromLong(value);
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceMetadata(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceMetadata() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }

  const char* arg0 = NULL;

  if (!PyArg_ParseTuple(args, "s", &arg0))
  {
    // TODO => RAISE : https://stackoverflow.com/questions/60832317
    PyErr_SetString(PyExc_TypeError, "Bad types for the arguments (1 arguments expected)");
    return NULL;
  }
  const char* s = OrthancPluginGetInstanceMetadata(OrthancPlugins::GetGlobalContext(), self->object_, arg0);
  
  if (s == NULL)
  {
    Py_INCREF(Py_None);
    return Py_None;
  }
  else
  {
    return PyUnicode_FromString(s);
  }
}

static PyObject *sdk_OrthancPluginDicomInstance_OrthancPluginGetInstanceOrigin(
  sdk_OrthancPluginDicomInstance_Object* self, PyObject *args)
{
  OrthancPlugins::LogInfo("Calling method OrthancPluginGetInstanceOrigin() on object of class OrthancPluginDicomInstance");

  if (self->object_ == NULL)
  {
    // TODO: RAISE
    //PythonLock::RaiseException(module, OrthancPluginErrorCode_NullPointer);
    PyErr_SetString(PyExc_ValueError, "Invalid object");
    return NULL;
  }


  OrthancPluginInstanceOrigin value = OrthancPluginGetInstanceOrigin(OrthancPlugins::GetGlobalContext(), self->object_);
  
  return PyLong_FromLong(value);
}



static void RegisterOrthancPluginDicomInstanceClass(PyObject* module)
{
  sdk_OrthancPluginDicomInstance_Type.tp_new = PyType_GenericNew;
  sdk_OrthancPluginDicomInstance_Type.tp_flags = Py_TPFLAGS_DEFAULT;
  sdk_OrthancPluginDicomInstance_Type.tp_doc = "Generated from Orthanc C class: OrthancPluginDicomInstance";
  sdk_OrthancPluginDicomInstance_Type.tp_methods = sdk_OrthancPluginDicomInstance_Methods;
  sdk_OrthancPluginDicomInstance_Type.tp_init = (initproc) sdk_OrthancPluginDicomInstance_Constructor;

  
  if (PyType_Ready(&sdk_OrthancPluginDicomInstance_Type) < 0)
  {
    OrthancPlugins::LogError("Cannot register Python class: OrthancPluginDicomInstance");
    ORTHANC_PLUGINS_THROW_EXCEPTION(InternalError);
  }

  Py_INCREF(&sdk_OrthancPluginDicomInstance_Type);
  if (PyModule_AddObject(module, "DicomInstance", (PyObject *)&sdk_OrthancPluginDicomInstance_Type) < 0)
  {
    OrthancPlugins::LogError("Cannot register Python class: OrthancPluginDicomInstance");
    Py_DECREF(&sdk_OrthancPluginDicomInstance_Type);
    ORTHANC_PLUGINS_THROW_EXCEPTION(InternalError);
  }
}


PyObject* GetOrthancPluginDicomInstanceType()
{
  return (PyObject*) &sdk_OrthancPluginDicomInstance_Type;
}