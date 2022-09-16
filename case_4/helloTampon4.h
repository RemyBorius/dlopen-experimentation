#ifndef HELLOTAMPON_H
#define HELLOTAMPON_H

#include "hello4.h"
#include "helloInterface4.h"

class HelloTampon : public Hello, public HelloInterface {
public:
    int helloInterfaceMethod(int otherInt) override;
};

// the class factories
extern "C" HelloInterface* create();

extern "C" void destroy(HelloInterface* p);

#endif
