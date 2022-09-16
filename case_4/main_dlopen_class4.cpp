#include "helloInterface4.h"
#include <iostream>
#include <dlfcn.h>

int main() {
    using namespace std;

    // load the library
    void* helloTampon = dlmopen(LM_ID_NEWLM, "./libhelloTampon4.so", RTLD_LAZY);
    if (!helloTampon) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // reset errors
    dlerror();

    // load the symbols
    create_t* create_hello = (create_t*) dlsym(helloTampon, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }

    destroy_t* destroy_hello = (destroy_t*) dlsym(helloTampon, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return 1;
    }

    // create an instance of the class
    HelloInterface* helloInterface = create_hello();

    // use the class
    helloInterface->helloInterfaceMethod(7);
//    cout << "The new helloInt is : " << helloInterface->helloInterfaceInt << endl;

    helloInterface->helloInterfaceMethod(8);
    helloInterface->helloInterfaceMethod(9);

    //===================================


    // load the library
    void* helloTampon2 = dlmopen(LM_ID_NEWLM, "./libhelloTampon4.so", RTLD_LAZY);
    if (!helloTampon2) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // reset errors
    dlerror();

    // load the symbols
    create_t* create_hello2 = (create_t*) dlsym(helloTampon2, "create");
    const char *dlsym_error2 = dlerror();
    if (dlsym_error2) {
        cerr << "Cannot load symbol create: " << dlsym_error2 << '\n';
        return 1;
    }

    destroy_t* destroy_hello2 = (destroy_t*) dlsym(helloTampon2, "destroy");
    dlsym_error2 = dlerror();
    if (dlsym_error2) {
        cerr << "Cannot load symbol destroy: " << dlsym_error2 << '\n';
        return 1;
    }


    // create an instance of the class
    HelloInterface* helloInterface2 = create_hello2();

    // use the class
    helloInterface2->helloInterfaceMethod(7);
    helloInterface2->helloInterfaceMethod(8);
    helloInterface2->helloInterfaceMethod(9);

    //==============================




    // destroy the class
    destroy_hello(helloInterface);

    // unload the triangle library
    dlclose(helloTampon);


    // destroy the class
    destroy_hello2(helloInterface2);

    // unload the triangle library
    dlclose(helloTampon2);
}