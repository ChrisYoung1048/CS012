#include <iostream>
using namespace std;
#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

  IntList l1;
  l1.push_back(1);


//   l1.push_back(4);
//   l1.insert_ordered(3);
//   l1.insert_ordered(5);
//   l1.insert_ordered(0);


//   IntList l;
//   l.insert_ordered(2);
cout << "one node '" << l1 << "'" << endl;

IntList l2;

cout << "empty list '"  << l2 << "'" << endl;

   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(300);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(400);
      cout << "pushback 400" << endl;
      list1.push_back(100);
      cout << "list1: " << list1 << endl;
      cout << endl;

      cout << "selection sort list1" << endl;
      list1.selection_sort();
      cout << "list1: " << list1 << endl;
      cout << endl;

      cout << "Calling copy constructor" << endl;
      IntList list4(list1);
      cout << "list4: " << list4 << endl;

      cout << "\nlist5 constructor called" << endl;
      IntList list5;
      list5 = list1;
      cout << "list5: " << list5 << endl;
      cout << endl;

      cout << "list1 clear" << endl;
      list1.clear();
      cout << "list1: " << list1 << endl;
      cout << endl;
      
      cout << "\nlist2 constructor called" << endl;
      IntList list2;
      cout << "list2: " << list2 << endl;
      cout << "pushback 400" << endl;
      list2.push_back(400);
      cout << "list2: " << list2 << endl;
      cout << endl;

      cout << "\nlist3 constructor called" << endl;
      IntList list3;
      cout << "list3: " << list3 << endl;
      cout << "insert ordered 3" << endl;
      list3.insert_ordered(3);
      cout << "list3: " << list3 << endl;
      cout << "insert ordered 5" << endl;
      list3.insert_ordered(5);
      cout << "list3: " << list3 << endl;
      cout << "insert ordered 4" << endl;
      list3.insert_ordered(5);
      cout << "list3: " << list3 << endl;
      cout << "insert ordered 1" << endl;
      list3.insert_ordered(6);
      cout << "list3: " << list3 << endl;
      cout << "insert ordered 6" << endl;
      list3.insert_ordered(6);
      cout << "list3: " << list3 << endl;

      list3.remove_duplicates();
      cout << "list3: " << list3 << endl;

      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
   
   return 0;
}
