#include "helloInterface3.h"
#include <iostream>
#include <dlfcn.h>

int main() {
    using namespace std;

    // load the triangle library
    void* hello = dlopen("./libhelloTampon.so", RTLD_NOW);
    if (!hello) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // reset errors
    dlerror();

    // load the symbols
    create_t* create_hello = (create_t*) dlsym(hello, "create");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }

    destroy_t* destroy_hello = (destroy_t*) dlsym(hello, "destroy");
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
    dlclose(hello);
}