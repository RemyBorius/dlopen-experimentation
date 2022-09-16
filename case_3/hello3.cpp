#include <iostream>
#include "hello3.h"

int Hello::helloMethod(int otherInt) {
    std::cout << "hello method (from `Hello` object) " << this->helloInt << " " << otherInt << '\n';
    this->helloInt = otherInt;
    return this->helloInt;
}
