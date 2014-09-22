// Jonathan Petersen
// A01236750
// Binomial Distribution
// Tree Class Header

#ifndef _TREE_H
#define _TREE_H

#include "Node.hpp"
#include <string>

using namespace std;

class Tree {

public:
	Tree(int);

	//Construct
	//Run
	void drop(Node*, int, int);

	//Destruct
	//Output
	void getOutput(Node*, int, string&);

	string result;

private:
	Node* root;
	static const int maxLevels = 9;

};

ostream& operator<< (ostream& out, const Tree& obj);


#endif
