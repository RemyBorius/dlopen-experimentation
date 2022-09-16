#ifndef HELLOINTERFACE_H
#define HELLOINTERFACE_H

class HelloInterface {
public:
    virtual ~HelloInterface() = 0;
    int helloInterfaceInt = 0;
    virtual int helloInterfaceMethod(int otherInt) = 0;
};

// the types of the class factories
typedef HelloInterface* create_t();
typedef void destroy_t(HelloInterface*);

#endif