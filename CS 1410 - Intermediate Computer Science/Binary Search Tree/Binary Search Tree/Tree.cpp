// Jonathan Petersen
// A01236750
// Binary Search Tree Assignment
// Binary Search Tree Implementation

#include <iostream>
#include <utility>
#include "Tree.hpp"

// Constructors
Tree::Tree() :
	root(NULL) {}

// Wrapper Functions
// Insert a Node Into the Tree
bool Tree::insert(int value) {

	Node<int>* parent;

	//Edge Cases
	if(root == NULL) { 

		// cout << "Inserting " << value << " at root" << endl;
		root = new Node<int>(value); 
		return true;
	}

	if(root->value == value) { 
	
		// cout << value << " already exists at root" << endl;
		return false; 
	}

	//Normal Case
	// cout << "Inserting " << value << " at root";
	parent = rFindParent(root, value);
	
	if(value < parent->value && parent->left == NULL) { 
	
		// cout << "->left" << endl; 
		parent->left = new Node<int>(value); 
		return true; 
	}

	if(value > parent->value && parent->right == NULL) { 

		// cout << "->right" << endl;
		parent->right = new Node<int>(value); 
		return true; 
	}

	if (value < parent->value && parent->left->value == value) {

		// cout << "\rFailed to insert " << value << " - Already Exists" << endl;
		return false;
	}

	if (value > parent->value && parent->right->value == value) {

		// cout << "\rFailed to insert " << value << " - Already Exists" << endl;
		return false;
	}

	return false;
}

// Remove a node from the Tree
bool Tree::remove(int value) {

	Node<int>* parent;

	//Edge Cases
	if(root == NULL) {

		// cout << "Failed to remove " << value << " - Does Not Exist" << endl;
		return false;
	}

	if(root->value == value) { 
	
		// cout << "Removed " << value << " at root" << endl;
		return rRemove(root, &root); 
	}

	parent = rFindParent(root, value);

	if(value < parent->value && parent->left == NULL) {
		// cout << "\rFailed to remove " << value << " - Does Not Exist" << endl;
		return false;
	}

	if(value > parent->value && parent->right == NULL) {
		// cout << "\rFailed to remove " << value << " - Does Not Exist" << endl;
		return false;
	}

	if(value < parent->value) {
		// cout << "\rRemoved " << parent->left->value << " at root";
		rFindParent(root, parent->left->value);
		// cout << "->left" << endl;
		return rRemove(parent->left, &(parent->left));

	}

	if(value > parent->value) {
		// cout << "\rRemoved " << parent->right->value << " at root";
		rFindParent(root, parent->right->value);
		// cout << "->right" << endl;
		return rRemove(parent->right, &(parent->right));
	}

	return false;
}

// Find a Node in the Tree
Node<int>* Tree::find(int target) 	{ 

	Node<int>* parent;

	//Edge Cases
	if(root == NULL) {
	
		// cout << target << " could not be found" << endl;
		return NULL;
	}

	if(root->value == target) {

		// cout << "Found " << target << " at root" << endl;
		return root;
	}	

	//Find the parent
	// cout << "Found " << target << " at root";
	parent = rFindParent(root, target);
	
	//Find Unsuccessful
	if((target < parent->value && parent->left	== NULL) ||
	   (target > parent->value && parent->right == NULL)) {

		// cout << "\r" << "Failed to find " << target << " - Does Not Exist" << endl;
		return NULL;
	}

	if(target < parent->value) {

		// cout << "->left" << endl;
		return parent->left;
	}

	if(target > parent->value) {

		// cout << "->right" << endl;
		return parent->right;
	}

	return NULL;
}

// Find the Laregest node of the tree
Node<int>* Tree::findMax() { 

	Node<int>* maximum;
	maximum = rFindMax(root);

	//The Comma operator assigns the value to maximum but then 
	//prints the maximum->value anyways.
	//cout << "Max: " << ((maximum = rFindMax(root)), maximum->value) 
	//	 << " at root"; 
	//rFindParent(root, maximum->value);
	// if(root != maximum) cout << "->right";
	// cout << endl;

	return maximum;
}

//Find the Smallest Node in the tree
Node<int>* Tree::findMin() { 

	Node<int>* minimum;
	minimum = rFindMin(root);

	//The Comma operator assigns the value to minimum but then 
	//prints the minimum->value anyways.
	//cout << "Min: " << ((minimum = rFindMin(root)), minimum->value) 
	//	 << " at root";
	//rFindParent(root, minimum->value);
	// if(root != minimum) cout << "->left";
	// cout << endl;

	return minimum;
}

//Traverse the tree in order and print that sucka.
void Tree::print() {
	
	// cout << "Printing tree" << endl;
	rPrint(root);
	// cout << "End print" << endl;

	return;
}

//Recursive Find function !FINDS THE PARENT NODE
Node<int>* Tree::rFindParent(Node<int>* node, int target) {

	//Base Case
	// if(node == NULL) return NULL;
	if(target < node->value && node->left == NULL) return node;
	if(target > node->value && node->right == NULL) return node;
	if(target < node->value && node->left->value == target) return node;
	if(target > node->value && node->right->value == target) return node;

	//Alternative Case
	// if(target < node->value) { cout << "->left"; return rFindParent(node->left, target); }
	// if(target > node->value) { cout << "->right"; return rFindParent(node->right, target); }

	return NULL;
}

// Recursive Function to find the Max
Node<int>* Tree::rFindMax(Node<int>* node) {

	//Base Cases
	if(node == NULL) return NULL;
	if(node->right == NULL) return node;

	//Alternative Case
	return rFindMax(node->right);

}

// Recursive Function to find the Min
Node<int>* Tree::rFindMin(Node<int>* node) {

	//Base Cases
	if(node == NULL) return NULL;
	if(node->left == NULL) return node;

	//Alternative Case
	return rFindMin(node->left);

}

//Recursive Function to remove nodes
typedef Node<int>* nodePtr;
bool Tree::rRemove(Node<int>* node, nodePtr* ptrToDelete) {

	//Base Case
	if(node->left == NULL && node->right == NULL) {
		delete node;
		*ptrToDelete = NULL;
		return true;
	}

	Node<int>* toDelete;

	if(node->left == NULL) { 
		toDelete = rFindMin(node->right);
		if(toDelete == node->right) ptrToDelete = &(node->right);
		else ptrToDelete = &(rFindParent(node, toDelete->value)->left);
	 }
	else {
		toDelete = rFindMax(node->left);
		if(toDelete == node->left) ptrToDelete = &(node->left);
		else ptrToDelete = &(rFindParent(node, toDelete->value)->right);
	}
	
	swap(node->value, toDelete->value); 
	return rRemove(toDelete, ptrToDelete);
}

//Recursive Function to traverse tree in order
void Tree::rPrint(Node<int>* node) {

	Node<int>* parent;

	//Base Case
	if(node == NULL) return;

	//Alternative Cases
	if(node->left != NULL) rPrint(node->left);
	// cout << node->value << " at root";
	if(node != root) {
		parent = rFindParent(root, node->value);
		// if(node->value < parent->value) cout << "->left";
		// if(node->value > parent->value) cout << "->right";
	}
	// cout << endl;
	if(node->right != NULL) rPrint(node->right);

	return;
}
