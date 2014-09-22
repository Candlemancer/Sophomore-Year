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
		left(NULL),
		right(NULL),
		parent(NULL) {}

	Node(T input) :
		value(input),
		left(NULL),
		right(NULL),
		parent(NULL) {}

	//Membmer Data
	T value;
	Node* left;
	Node* right;
	Node* parent;
};

#endif
