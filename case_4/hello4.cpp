#include <iostream>
#include "hello4.h"
int globalInt = 0;

int Hello::helloMethod(int otherInt) {
    std::cout << "hello method (from `Hello` object) " << this->helloInt << " " << otherInt << '\n';
    std::cout << "Static Int : " << globalInt++ << '\n';
    this->helloInt = otherInt;
    return this->helloInt;
}
