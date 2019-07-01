#include <Python.h>
#include <iostream>

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3)
    {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    // Initialize the Python Interpreter
    Py_Initialize();

    // Build the name object
    pName = PyUnicode_FromString(argv[1]);

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);

    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, argv[2]);

    std::cout << "here";

    if (PyCallable_Check(pFunc))
    {
        PyObject_CallObject(pFunc, NULL);
    } else
    {
        PyErr_Print();
    }

    // Clean up
    //Py_DECREF(pModule);
    //Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

    return 0;
}
