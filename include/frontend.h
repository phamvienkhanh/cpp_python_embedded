#ifndef _INC_FRONTEND_H
#define _INC_FRONTEND_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

class FrontEnd
{
public:
	static bool AddModulePath(const char* path);

public:
	bool loadModule(const char* moduleName);
	int callFunc(const char* funcName, int a, int b);

	FrontEnd();
	~FrontEnd();

private:
	const char* m_moduleName;
	PyObject*   m_module;	
};

#endif