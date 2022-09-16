#include "helloInterface.h"  // possible in my usecase ??

class Hello : public HelloInterface {
public:
//    int helloInt = 0;
    virtual int helloMethod(int otherInt);
};

// Is following code possible in my usecase ? I don't know for now
extern "C" HelloInterface* create();

extern "C" void destroy(HelloInterface* p);