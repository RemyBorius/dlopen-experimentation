#ifndef HELLO_H
#define HELLO_H

//#include "helloInterface3.h"  // possible in my usecase ??

class Hello {
public:
    int helloInt = 0;
    int helloMethod(int otherInt);
};

#endif