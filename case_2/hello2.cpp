#include <iostream>
#include "hello2.h"

int Hello::helloMethod(int otherInt) {
    std::cout << "hello method (from `Hello` object) " << this->helloInt << " " << otherInt << '\n';
    this->helloInt = otherInt;
    return this->helloInt;
}

// Following code is not possible in my personal usecase (as I cannot modify the proprietary code)

// the class factories
extern "C" HelloInterface* create() {
    return new Hello;
}

extern "C" void destroy(HelloInterface* p) {
    delete p;
}