#include "backend.h"

#include <iostream>

PyObject* addTwoNums(PyObject *self, PyObject *args) {
	int a;
	int b;
	if(!PyArg_ParseTuple(args, "ii", &a, &b))
		return NULL;

	std::cout << "argvs: " << a << " " << b << std::endl;

	return PyLong_FromLong(a+b);
}