#ifndef HELLOTAMPON_H
#define HELLOTAMPON_H

#include "hello3.h"
#include "helloInterface3.h"

class HelloTampon : public Hello, public HelloInterface {
public:
    ~HelloTampon() override = default;
    int helloInterfaceMethod(int otherInt) override;
};

// the class factories
extern "C" HelloInterface* create();

extern "C" void destroy(HelloInterface* p);

#endif
