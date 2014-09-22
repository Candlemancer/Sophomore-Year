// Jonathan Petersen
// A01236750
// Reuseable Code
// Node Class Template

#ifndef _NODE_H
#define _NODE_H

#include <string>

using namespace std;

template <class T>
class Node {

public:
	//Constructors
	Node() :
		value(),
		next(NULL) {}

	Node(T input) :
		value(input),
		next(NULL) {}

	//Membmer Data
	T value;
	Node* next;
};

#endif
