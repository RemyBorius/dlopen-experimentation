#ifndef HELLOINTERFACE_H
#define HELLOINTERFACE_H

class HelloInterface {
public:
    int helloInt = 0;
    virtual ~HelloInterface() {};
    virtual int helloMethod(int otherInt) = 0;
};

// the types of the class factories
typedef HelloInterface* create_t();
typedef void destroy_t(HelloInterface*);

#endif