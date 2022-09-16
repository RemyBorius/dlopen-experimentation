#include <iostream>
#include <dlfcn.h>
#include "hello.h"

int main() {
    using namespace std;

    cout << "C++ case_1 " << endl << endl;

    // open the library (it must have been compiled first)
    cout << "Opening hello.so...\n" << endl;
    void* handle = dlmopen(LM_ID_NEWLM, "./libhello.so", RTLD_NOW);

    // Chek if the lib opened correctly
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }

    ///////////// Test for helloFunction (aka not a method) ////////////////////

    // load helloFunction
    cout << "Loading symbol helloFunction ...\n";
    int (*helloFunction)(int);
    // reset errors
    dlerror();
    *(void**)(&helloFunction) = dlsym(handle, "_Z13helloFunctioni");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'helloFunction': " << dlsym_error <<
             '\n';
        dlclose(handle);
        return 1;
    }

    // Test the loaded helloFunction
    cout << "Calling helloFunction...\n";
    int res = helloFunction(4);
    cout << "res " << res << endl;


    ///////////// Test for helloMethod (aka a method) ////////////////////

    // load helloMethod

    cout << endl << "Loading symbol helloMethod" << endl << endl;
    int (Hello::*helloMethod)(int);
    // reset errors
    dlerror();
    *(void**)(&helloMethod) = dlsym(handle, "_ZN5Hello11helloMethodEi");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error2) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error2 <<
             '\n';
        dlclose(handle);
        return 1;
    }

    // Test the loaded helloMethod
    cout << "Calling helloMethod \n";
    Hello helloInstance{};
    int res2 = (helloInstance.*helloMethod)(4);
    cout << "res " << res2 << endl;


    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}