#include "helloTampon.h"
#include "iostream"

HelloTampon::~HelloTampon() {}

int HelloTampon::helloInterfaceMethod(int otherInt) {
    this->helloInterfaceInt = this->helloMethod(otherInt);
    return this->helloInterfaceInt;
}

// the class factories
extern "C" HelloInterface* create() {
    return new HelloTampon;
}

extern "C" void destroy(HelloInterface* p) {
    delete p;
}
