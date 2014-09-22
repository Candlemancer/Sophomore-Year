// Jonathan Petersen
// A01236750
// Binary Search Tree Assignment
// Binary Search Tree Header

#include "Node.hpp"

class Tree {

public:
	// Constructors
	Tree();

	// Wrapper Functions
	bool insert(int);
	bool remove(int);
	Node<int>* Tree::find(int);
	Node<int>* Tree::findMax();
	Node<int>* Tree::findMin();
	void print();
	
private:
	//Recursive Functions
	Node<int>* rFindParent(Node<int>*, int);
	Node<int>* rFindMax(Node<int>*);
	Node<int>* rFindMin(Node<int>*);
	bool rRemove(Node<int>*,Node<int>**);
	void rPrint(Node<int>*);

	// Data Members
	Node<int>* root;

};

