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

int &IntVector::at(unsigned index) {
    if (index < 0 || index > sz - 1 || sz == 0)
        throw out_of_range("IntVector::at_range_check");
    else {
        return *(data+index);
    }
}

void IntVector::insert(unsigned index, int value) {
    if (index < 0 || index > sz)
        throw out_of_range("IntVector::insert_range_check");
    if (sz >= cap)
        expand();
    for (unsigned i = sz; i > index; --i) {
        *(data+i) = *(data+i-1);
    }
    *(data+index) = value;
    sz++;
}

void IntVector::erase(unsigned index) {
    if (index < 0 || index >= sz)
        throw out_of_range("IntVector::erase_range_check");
    else {
        for (unsigned i = index; i < sz-1; ++i) {
            *(data+i) = *(data+i+1);
        }
    }
    sz--;
}

const int &IntVector::front() const {
    return *data;
}

int &IntVector::front() {
    return *data;
}

const int&IntVector::back() const {
    return *(data+sz-1);
}

int &IntVector::back() {
    return *(data+sz-1);
}

void IntVector::assign(unsigned n, int value) {
    if (n > cap) {
        if (n-cap > cap)
            expand(n-cap);
        else
            expand();
    }
    for (unsigned i = 0; i < n; ++i) {
        *(data+i) = value;
    }
    sz = n;
}

void IntVector::push_back(int value) {
    if (sz >= cap)
        expand();
    *(data+sz) = value;
    sz++;
}

void IntVector::pop_back() {
    sz--;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size > cap) {
        if (size-cap > cap)
            expand(size-cap);
        else
            expand();
       
    }  
    if (size <= sz) {
        sz = size;
    } 
    else {
        for (unsigned i = sz; i < size; ++i) {
                *(data+i) = value;
            }
        sz = size;
    }
    /*else if (size > sz) {
        for (unsigned i = sz; i < size; ++i) {
            *(data+i) = value;
        }
        sz += (size-sz);
    }*/
}

void IntVector::reserve(unsigned n) {
    if (n < cap)
        return;
    cap = n;
}

void IntVector::expand() { //What is the capcity = 0 case;
    if (cap == 0)  
        cap++;
    else 
        cap *= 2;
    int *temp = new int[cap];
    //Transfer values of old array to new array
    for (unsigned i = 0; i < sz; ++i) {
        *(temp+i) = *(data+i);
    }
    //Set empty values to zero
    for (unsigned i = sz; i < cap; ++i) {
        *(temp+i) = 0;
    }
    delete data;
    data = temp;
}   

void IntVector::expand(unsigned amount) {
    cap += amount;
    int *temp = new int[cap];
    //Transfer values of old array to new array
    for (unsigned i = 0; i < sz; ++i) {
        *(temp+i) = *(data+i);
    }
    //Set empty values to zero
    for (unsigned i = sz; i < cap; ++i) {
        *(temp+i) = 0;
    }
    delete data;
    data = temp;
}
