/*
#ifndef EXEC_PYTHON_H
#define EXEC_PYTHON_H
#include "utility.h"
// "C:\Program Files\WindowsApps\PythonSoftwareFoundation.Python.3.7_3.7.1520.0_x64__qbz5n2kfra8p0\include\python.h"
#include <Python.h>


inline std::string Exec_python(){

    // Set PYTHONPATH TO working directory
    setenv("PYTHONPATH",".",1);

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;


    // Initialize the Python Interpreter
    Py_Initialize();


    // Build the name object
    pName = PyString_FromString((char*)"arbName");

    // Load the module object
    pModule = PyImport_Import(pName);


    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);


    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, (char*)"someFunction");

    if (PyCallable_Check(pFunc))
    {
        pValue=Py_BuildValue("(z)",(char*)"something");
        PyErr_Print();
        printf("Let's give this a shot!\n");
        presult=PyObject_CallObject(pFunc,pValue);
        PyErr_Print();
    } else
    {
        PyErr_Print();
    }
    printf("Result is %d\n",PyInt_AsLong(presult));
    Py_DECREF(pValue);

    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

}


#endif // EXEC_PYTHON_H
*/
