#include "helloInterface3.h"
#include <iostream>
#include <dlfcn.h>

int main() {
    using namespace std;

    // load the library
    void* helloTampon = dlopen("./libhelloTampon.so", RTLD_NOW);
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
    cout << "The new helloInt is : " << helloInterface->helloInterfaceInt << endl;

    // destroy the class
    destroy_hello(helloInterface);

    // unload the triangle library
    dlclose(helloTampon);
}