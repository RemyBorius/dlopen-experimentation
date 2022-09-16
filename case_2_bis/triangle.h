#include "polygon.hpp"

class triangle : public polygon {
public:
    virtual double area() const;
};


// the class factories

extern "C" polygon* create();

extern "C" void destroy(polygon* p);
