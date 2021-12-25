#include "frontend.h"

FrontEnd::FrontEnd()
{
	
}

FrontEnd::~FrontEnd()
{
	Py_XDECREF(m_module);
}

bool FrontEnd::AddModulePath(const char* path)
{
	PyObject* sysPath = PySys_GetObject((char*)"path");
	int rs = PyList_Append(sysPath, PyUnicode_FromString(path));
	if (rs == -1) {
		PyErr_Print();
		return false;
	}

	return true;
}

bool FrontEnd::loadModule(const char* moduleName)
{
	if(m_module)
		Py_DECREF(m_module);

	PyObject* pyModuleName = PyUnicode_DecodeFSDefault(moduleName);
	m_module = PyImport_Import(pyModuleName);
	Py_DECREF(pyModuleName);

	if(!m_module) {
		PyErr_Print();
		return false;
	}

	return true;
}

int FrontEnd::callFunc(const char* funcName, int a, int b)
{
	if(m_module) {
		PyObject* func = PyObject_GetAttrString(m_module, funcName);
		
		if(func && PyCallable_Check(func)) {
			PyObject* args = PyTuple_New(2);

			PyObject* value = PyLong_FromLong(a);
			PyTuple_SetItem(args, 0, value);

			value = PyLong_FromLong(b);
			PyTuple_SetItem(args, 1, value);

			value = PyObject_CallObject(func, args);
			Py_DECREF(func);

			int rs = PyLong_AsLong(value);
			Py_DECREF(value);

			return rs;	
		}

	}

	return 0;	
}