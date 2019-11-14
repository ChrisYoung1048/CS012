#include <iostream>
using namespace std;
#include "IntVector.h"

string print(const IntVector &v);

int main() {
    //Testing harness
    cout << "[Testing Harness for IntVector]" << endl << endl;

    //Testing size(), capacity(), at()
    cout << "Instantiated testVector1 with size at 10 and value at 0" << endl;
    IntVector testVector1(10, 0);

    cout << "testing testVector1.size()..." << endl;
    cout << "testVector1 size = " << testVector1.size() << endl;
    cout << "testing testVector1.capacity()..." << endl;
    cout << "testVector1 capacity = " << testVector1.capacity() << endl;
    cout << "testing testVector2.at(0)..." << endl;
    cout << "testVector1.at(0) = " << testVector1.at(0) << endl;  

    cout << endl;

    //Testing empty()
    cout << "Instantiated testVector2 with default constructor" << endl;
    IntVector testVector2;
    cout << "Instantiated testVector3 with size at 10 and value at 0" << endl;
    IntVector testVector3(10, 0);
    
    cout << "Testing testVector2.empty()..." << endl;
    cout << "testVector2 empty status = " << testVector2.empty() << endl;
    cout << "Testing testVector3.empty()..." << endl; 
    cout << "testVector3 empty status = " << testVector3.empty() << endl;

    cout << endl;

    //Testing expand() 
    //expand() methods need to be made public to be tested
    /*
    cout << "Instantiated testVector4 with default constructor" << endl;
    IntVector testVector4;
    cout << "Instantiated testVector5 with size at 10 and value at 0" << endl;
    IntVector testVector5(10, 0);

    cout << "testVector4 capacity = " << testVector4.capacity() << endl;
    cout << "Testing testVector4.expand()..." << endl;
    testVector4.expandTest(testVector4);
    cout << "testVector4 capacity = " << testVector4.capacity() << endl;
    

    cout << "testVector5 capacity = " << testVector5.capacity() << endl;
    cout << "Testing testVector5.expand()..." << endl;
    testVector5.expandTest(testVector5);
    cout << "testVector5 capacity = " << testVector5.capacity() << endl;
    cout << "Testing testVector5.expand(5)..." << endl;
    testVector5.expandTest(testVector5, 5);
    cout << "testVector5 capacity = " << testVector5.capacity() << endl;
    */
    
    //Testing insert(), erase(), pushback(), pop_back(), and clear()
    cout << "Instantiated testVector6 with size at 10 and value at 0" << endl;
    IntVector testVector6(10, 0);

    cout << "testVector6: " << print(testVector6) << endl;
    cout << "Testing testVector6.insert(4,1)..." << endl;
    testVector6.insert(4, 1);
    /* cout << "Testing exception with testVector6.insert(11,1)..." << endl;
    testVector6.insert(11, 1); */
    cout << "testVector6: " << print(testVector6) << endl;
    cout << "Testing testVector6.erase(3)..." << endl;
    testVector6.erase(3);
    /* cout << "Testing exception with testVector6.erase(11)..." << endl;
    testVector6.erase(11); */
    cout << "testVector6: " << print(testVector6) << endl;
    cout << "Testing testVector6.push_back(5)..." << endl;
    testVector6.push_back(5);
    cout << "testVector6: " << print(testVector6) << endl;
    cout << "Testing testVector6.pop_back()..." << endl;
    testVector6.pop_back();
    cout << "testVector6: " << print(testVector6) << endl;
    cout << "Testing testVector6.clear()..." << endl;
    testVector6.clear();
    cout << "testVector6: " << print(testVector6) << endl;

    cout << endl;
    
    //Testing resize()
    cout << "Instantiated testVector7 with size at 3 and value at 0" << endl;
    IntVector testVector7(3, 0);

    cout << "testVector7: " << print(testVector7) << endl;
    cout << "Testing testVector7.resize(1,0)..." << endl;
    testVector7.resize(1, 0);
    cout << "testVector7: " << print(testVector7) << endl;
    cout << "current cap = " << testVector7.capacity() << endl;
    cout << "Testing testVector7.resize(3,2)..." << endl;
    testVector7.resize(3, 2);
    cout << "testVector7: " << print(testVector7) << endl;
    cout << "current cap = " << testVector7.capacity() << endl;
    cout << "Testing testVector7.resize(10,0)..." << endl;
    testVector7.resize(10, 0);
    cout << "testVector7: " << print(testVector7) << endl;
    cout << "current cap = " << testVector7.capacity() << endl;
    cout << "Testing testVector7.resize(10,0)..." << endl;
    testVector7.resize(11,0);
    cout << "testVector7: " << print(testVector7) << endl;
    cout << "current cap = " << testVector7.capacity() << endl;

    cout << endl;

    //Testing reserve()
    cout << "Instantiated testVector8 with size at 10 and value at 0" << endl;
    IntVector testVector8(10, 0);

    cout << "testVector8: " << print(testVector8) << endl;
    cout << "Testing testVector7.reserve(11)..." << endl;
    testVector8.reserve(11);
    cout << "current cap = " << testVector8.capacity() << endl;
    cout << "Testing testVector7.reserve(9)..." << endl;
    testVector8.reserve(9);
    cout << "current cap = " << testVector8.capacity() << endl;

    cout << endl;

    //Testing assign()
    cout << "Instantiated testVector9 with size at 3 and value at 0" << endl;
    IntVector testVector9(3, 0);

    cout << "testVector9: " << print(testVector9) << endl;
    cout << "Testing testVector9.assign(2,1)..." << endl;
    testVector9.assign(2,1);
    cout << "testVector9: " << print(testVector9) << endl;
    cout << "current cap = " << testVector9.capacity() << endl;
    cout << "Testing testVector9.assign(10,1)..." << endl;
    testVector9.assign(10,1);
    cout << "testVector9: " << print(testVector9) << endl;
    cout << "current cap = " << testVector9.capacity() << endl;
    cout << "Testing testVector9.assign(11,1)..." << endl;
    testVector9.assign(11,1);
    cout << "testVector9: " << print(testVector9) << endl;
    cout << "current cap = " << testVector9.capacity() << endl;

    cout << endl;

    //Testing front() and back()
    cout << "Instantiated testVector10 with 5 values in ascending order" << endl;
    IntVector testVector10;
    for (unsigned i = 0; i < 5; ++i) {
        testVector10.push_back(i);
    }
    
    cout << "testVector10: " << print(testVector10) << endl;
    cout << "Testing testVector10.front()..." << endl;
    cout << "Front = " << testVector10.front() << endl;
    cout << "Testing testVector10.back()..." << endl;
    cout << "Back = " << testVector10.back() << endl;

    return 0;
}

string print(const IntVector &v){
    if (v.size() == 0)
        return "{}";
    string str = "";
    str += "{";
    for (unsigned i = 0; i < v.size(); ++i) {
        str += to_string(v.at(i));
        if (i < v.size()-1)
            str += ", ";
    }
    str += "}";
    return str;
}