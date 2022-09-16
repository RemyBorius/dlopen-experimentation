#include <iostream>
#include "hello.h"
int Hello::helloMethod(int otherInt) {
    std::cout << "hello method (from `Hello` object) " << this->helloInt << " " << otherInt << '\n';
    return this->helloInt;
}

int helloFunction(int newint){
    std::cout << "hello function " << '\n';
    return newint;
}
