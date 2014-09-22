// Jonathan Petersen
// A01236750
// Binomial Distribution
// Tree Class Implementation

#include <cstdlib>
#include "Tree.hpp"
#include "Node.hpp"

using namespace std;

Tree::Tree(int numBalls) {

	//Initialize the Randomness

	//Construct the right hand side of the tree
	root = new Node();
	root->value = 1;

	drop(root, numBalls, 1);
	getOutput(root, 1, result);

	result = result.substr(0, result.length() - 1);

}

void Tree::drop(Node* thisNode, int numBalls, int level) {

	//Find out how many balls are going left and right.
	int lBalls = 0;
	int rBalls = 0;
	int llBalls = 0;
	int lrBalls = 0;
	int rlBalls = 0;
	int rrBalls = 0;

	for (int i=0; i<numBalls; i++) {

		if(rand() % 2) lBalls++;
		else rBalls++;

	}

	for (int i=0; i<lBalls; i++) {

		if(rand() % 2) llBalls++;
		else lrBalls++;
		
	}

	for (int i=0; i<rBalls; i++) {

		if(rand() % 2) rlBalls++;
		else rrBalls++;
		
	}


	//Make the next layer if it doesn't exist.
	if(thisNode->l == NULL) {
		thisNode->l = new Node();
		thisNode->l->value = lBalls;
	}

	if(thisNode->r == NULL) {
		thisNode->r = new Node();
		thisNode->r->value = rBalls;
	}

	//Base Cases
	if(level == maxLevels - 1) {
		thisNode->l->l = NULL;
		thisNode->l->r = NULL;
		thisNode->r->l = NULL;
		thisNode->r->r = NULL;
		return;
	}

	//Alternative Cases

	//Make the next next layer if it doesn't exist.
	if(thisNode->l->l == NULL) {
		thisNode->l->l = new Node();
		thisNode->l->l->value = llBalls;
	}
	if(thisNode->l->r == NULL) {
		thisNode->l->r = new Node();
		thisNode->l->r->value = lrBalls;
	}

	thisNode->r->l = thisNode->l->r;
	thisNode->r->l->value += rlBalls;

	if(thisNode->r->r == NULL) {
		thisNode->r->r = new Node();
		thisNode->r->r->value = rrBalls;
	}

	//Move down the tree
	drop(thisNode->l, thisNode->l->value, level + 1);
	drop(thisNode->r, thisNode->r->value, level + 1);

	return;
}

void Tree::getOutput(Node* thisNode, int level, string& result) {

	//Base Case
	if(level == maxLevels - 2) {
		if(thisNode->l != NULL) {
			if(thisNode->l->l != NULL) {
				result += (to_string(thisNode->l->l->value) + "-");
				delete thisNode->l->l;
				thisNode->l->l = NULL;

				result += (to_string(thisNode->l->r->value) + "-");
				delete thisNode->l->r;
				thisNode->l->r = NULL;
			}
		}

		if(thisNode->r != NULL) {
			if (thisNode->r->r != NULL) {
			
				thisNode->r->l = NULL;
		
				result += (to_string(thisNode->r->r->value) + "-");
				delete thisNode->r->r;
				thisNode->r->r = NULL;
			}
		}

		return;
	}

	//Alternative Case

	if(thisNode->l != NULL)	getOutput(thisNode->l, level + 1, result);
	thisNode->r->l = NULL;
	getOutput(thisNode->r, level + 1, result);

	if(thisNode->l != NULL) {
		if(thisNode->l->l != NULL) {
			delete thisNode->l->l;
			thisNode->l->l = NULL;

			delete thisNode->l->r;
			thisNode->l->r = NULL;
		
		}
	}

	if(thisNode->r != NULL) {
		if (thisNode->r->r != NULL) {
		
			thisNode->r->l = NULL;

			delete thisNode->r->r;
			thisNode->r->r = NULL;
		}
	}


	return;

}

ostream& operator<< (ostream& out, const Tree& obj) {

	out << obj.result;

	return out;
}
