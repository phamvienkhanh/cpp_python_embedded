#ifndef _INC_BACKEND_H_
#define _INC_BACKEND_H_

#define PY_SSIZE_T_CLEAN
#include <Python.h>

/**
 * functions API
 * */

PyObject* addTwoNums(PyObject *self, PyObject *args);
//-------------------------------------------------------------


/**
 * init methods
 * */
static PyMethodDef s_backendMethods[] = {
    {"addTwoNums", addTwoNums, METH_VARARGS,
     "Return the number of arguments received by the process."},
    {NULL, NULL, 0, NULL}
};
//-------------------------------------------------------------


/**
 * init module
 * */
static PyModuleDef s_backendModule = {
    PyModuleDef_HEAD_INIT, "backend", NULL, -1, s_backendMethods,
    NULL, NULL, NULL, NULL
};
//-------------------------------------------------------------

/**
 * create module
 * */
static PyObject* PyInit_backend(void) {
    return PyModule_Create(&s_backendModule);
}


/**
 * register module
 * */
static void Resigter_backend() {
	PyImport_AppendInittab("backend", &PyInit_backend);
}

#endif