#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &list) {
   out << list.head;
   return out;
}

bool IntList::exists(int value) const {
   return exists(head, value);
}

bool IntList::exists(IntNode *node, int value) const{
   if (node == nullptr) {
      return false;
   } else if (node->data == value) {
      return true;
   } 
   return exists(node->next, value);
}

ostream & operator<<(ostream &out, IntNode *node) {
   if (node == nullptr) {
      return out;
   } else if (node->next == nullptr) {
      out << node->data;
   } else {
      out << node->data << " ";
   }
   return out << node->next;
}