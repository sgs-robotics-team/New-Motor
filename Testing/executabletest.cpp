#include <Python.h>
#include <iostream>
#include <stdio.h>


using namespace std;

int main(int argc, char *argv[]){
  int i = 0;
   while(i<3){
   cout<<"start"<<endl;
   Py_Initialize();
   FILE* file;
   wchar_t* _argv[argc];
   for(int i=0; i<argc; i++){
       wchar_t *arg = Py_DecodeLocale(argv[i], NULL);
       _argv[i] = arg;
   }

   PySys_SetArgv(argc, _argv);
   PyObject *sys = PyImport_ImportModule("sys");
   PyObject *path = PyObject_GetAttrString(sys, "path");

   PyList_Append(path, PyUnicode_FromString("."));
   file = fopen("./et.py","r");
   PyRun_SimpleFile(file, "./et.py");
   fclose(file);
   Py_Finalize();
   cout<<"Done"<<endl;
   i++;
   }
  return 0;
}
