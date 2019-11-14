#include <iostream>
using namespace std;
#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    IntNode* current = this->head;
    while (current) {
        IntNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front() {
    if (head == nullptr) {
        return;
    } else if (tail == head) {
        delete head;
        head = tail = nullptr;
    } else {
        IntNode *temp = head;
        delete head;
        head = temp->next;
    }
}

bool IntList::empty() const {
    if (head == nullptr)
        return true;
    return false;
}

const int &IntList::front() const {
    return head->data;
}

const int &IntList::back() const {
    return tail->data;
}

ostream &operator<<(ostream &out, const IntList &list) {
    IntNode *current = list.head;
    while (current) {
        if (current->next == nullptr) {
            cout << current->data;
            current = current->next;
        }
        else {
            cout << current->data << " ";
            current = current->next;
        }
    }
    return out;    
}