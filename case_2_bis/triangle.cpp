#include "triangle.h"
#include <cmath>

double triangle::area() const {
    return side_length_ * side_length_ * sqrt(3) / 2;
}


// the class factories

extern "C" polygon* create() {
    return new triangle;
}

extern "C" void destroy(polygon* p) {
    delete p;
}
