// Jonathan Petersen
// A01236750
// Various
// Node Class Header

#ifndef _NODE_H
#define _NODE_H

using namespace std;

class Node {

public:
	Node() :
		data(0) {}
	Node(int data) :
		data(data) {}

	inline int getData() 			{ return data; }
	// inline int setData(int data) { this->data = data; }

	inline Node* getNext() 			{ return next; }
	inline void setNext(Node* next) { this->next = next; }

private:
	int data;
	Node* next;

};

#endif
