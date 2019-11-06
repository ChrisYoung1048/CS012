#include <iostream>
#include <stdexcept>
using namespace std;
#include "IntVector.h"

IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = new int[cap];
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[cap];
    for (unsigned i = 0; i < size; ++i) {
        *(data+i) = value; 
    }
    //*data = value;
}

IntVector::~IntVector() {
    delete[] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz == 0)
        return true;
    return false;
}

const int &IntVector::at(unsigned index) const {
    if (index < 0 || index > sz - 1 || sz == 0)
        throw out_of_range("IntVector::at_range_check");
    else {
        return *(data+index);
    }
}

const int &IntVector::front() const {
    return *data;
}

const int&IntVector::back() const {
    return *(data+sz-1);
}