#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	IntList(const IntList &cpy); //Implement
	~IntList();
	void push_front(int);
	void push_back(int value); //Implement
	void pop_front();
	void clear(); //Implement
	void selection_sort(); //Implement
	void insert_ordered(int value); //Implement
	void remove_duplicates(); //Implement
	bool empty() const;
	const int & front() const;
	const int & back() const;
	friend ostream & operator<<(ostream &, const IntList &);
	IntList & operator=(const IntList &rhs); //Implement
};

#endif

