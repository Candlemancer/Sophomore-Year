#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream outputFile; //outputFile is defined as a global variable

struct TreeNode
{
	int key;
	TreeNode *left;				
	TreeNode *right;				

	//constructor of the struct
	TreeNode (int key1, TreeNode *left1 = NULL, TreeNode *right1 = NULL)
	{
		key = key1;
		left = left1;
		right = right1;
	}
};

class BST
{
	private:
		TreeNode * root; // the root of the tree
		void destroySubTree(TreeNode *);// delete all nodes of the tree
		void displayPreOrder(TreeNode *); //function overload, pre-order traversal
		void displayInOrder(TreeNode *);//function overload, in-order traversal
		void displayPostOrder(TreeNode *); //function overload, post-order traversal

	public:
		BST() { root = NULL; }
		~BST() { destroySubTree(root); }
		void displayPreOrder() { displayPreOrder(root); }// pre-order traversal
		void displayInOrder() { displayInOrder(root); }//in-order traversal
		void displayPosteOrder() { displayPostOrder(root); }//post-order traversal
		void insert(int x);//please complete this function
		void remove(int x);//please complete this function
		bool search(int x);//please complete this function
		int findMin();//please complete this function
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750
// Most of these are iterative rewrites of my old recursive solutions.

//please complete this function: insert a new node with key x
void BST::insert(int x) {

	TreeNode* node = root;
	TreeNode* prev = node;

	if (root == NULL) {

		root = new TreeNode(x);
		return;
	}

	// Find node and its parent.
	while (node != NULL && node->key != x) {

		prev = node;

		if(x < prev->key) { node = node->left; continue; }
		if(x > prev->key) { node = node->right; continue; }

	}

	if (node == NULL) {

		if (x < prev->key) { prev->left = new TreeNode(x); return; }
		if (x > prev->key) { prev->right = new TreeNode(x); return; }

	}

	return;
}

//please complete this function: remove the node whose key is x
void BST::remove(int x) {

	TreeNode* node = root;
	TreeNode* prev = node;

	// Edge cases
	if (root == NULL) return;

	if (root->key == x) {

		//Select the largest node of the right subtree.
		node = node->right;

		// If no right subtree, just go left.
		if (node == NULL) {

			root = root->left;
			// cout << "Deleting " << prev->key << endl;
			delete prev;
			return;

		}

		// When only one node to the right
		if (node->left == NULL) {
			
			swap(root->key, node->key);
			prev->right = node->right;
			// cout << "Deleting " << node->key << endl;
			delete node;
			return;

		}

		while (node->left != NULL) {

			prev = node;
			node = node->left;

		}
	
		//Switch the two node objects.
		std::swap(root->key, node->key);
		prev->left = node->right;
		// cout << "Deleting " << node->key << endl;
		delete node;		

	}

	// Find node and its parent.
	while (node != NULL && node->key != x) {

		prev = node;

		if(x < prev->key) { node = node->left; continue; }
		if(x > prev->key) { node = node->right; continue; }
		//cout << "x: " << x << endl;
		//cout << "prev->key: " << prev->key << endl;

	}

	// Edge Cases
	if (node == NULL) {
		cout << x << " not found in tree!" << endl;
		return;
	}

	TreeNode* toDelete = node;

	//Select the largest node of the right subtree.
	node = node->right;

	// If no right subtree, just go left.
	if (node == NULL) {

		if (toDelete->key < prev->key) { prev->left = toDelete->left; }
		if (toDelete->key > prev->key) { prev->right = toDelete->left; }
		// cout << "Deleting " << toDelete->key << endl;
		delete toDelete;
		return;

	}

	// When only one node to the right
	if (node->left == NULL) {
		
		swap(toDelete->key, node->key);
		toDelete->right = node->right;
		// cout << "Deleting " << node->key << endl;
		delete node;
		return;

	}

	while (node->left != NULL) {

		prev = node;
		node = node->left;

	}

	//Switch the two node objects.
	std::swap(toDelete->key, node->key);
	prev->left = node->right;
	// cout << "Deleting " << node->key << endl;
	delete node;		

	return;
}

//please complete this function: if x is in the tree, return true;
//otherwise return false
bool BST::search(int x) {

	TreeNode* node = root;

	//Edge cases
	if (root == NULL) return false;
	if (root->key == x) return true;

	//Move the pointer left or right as needed until a result is found.
	while (node != NULL && node->key != x) {

		if (x < node->key) { node = node->left;  continue; }
		if (x > node->key) { node = node->right; continue; }

	}

	//If you want to return the node or value, magick here.
	if (node == NULL) return false;
	return true;
}

//please complete this function: return the smallest key in the tree
int BST::findMin() {

	TreeNode* node = root;

	//Move the pointer to the smallest node
	while (node->left != NULL) {

		node = node->left;

	}

	return node->key;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void BST::destroySubTree(TreeNode *v)
{
	if (v == NULL)
		return;
	else
	{
		destroySubTree(v->left);
		destroySubTree(v->right);
		delete v;
	}
}

void BST::displayPreOrder(TreeNode *v)
{
	if (v != NULL)
	{
		cout << v->key << "  ";
		outputFile << v->key << "  ";
		displayPreOrder(v->left);
		displayPreOrder(v->right);
	}
}

void BST::displayInOrder(TreeNode *v)
{
	if (v != NULL)
	{
		displayInOrder(v->left);
		cout << v->key << "  ";
		outputFile << v->key << "  ";
		displayInOrder(v->right);
	}
}

void BST::displayPostOrder(TreeNode *v)
{
	if (v != NULL)
	{
		displayPostOrder(v->left);
		displayPostOrder(v->right);
		cout << v->key << "  ";
		outputFile << v->key << "  ";
	}
}

int main()
{
	BST tree;

	string inputFileName = "hw3_Q1_input.txt"; // input file with operations 
	string outputFileName = "hw3_Q1_output.txt"; // output file

	//open files
	ifstream inputFile;
	inputFile.open(inputFileName.c_str());
	if (!inputFile)
		cout << "Error opening the input file " << endl;
	
	outputFile.open(outputFileName.c_str());
	if (!outputFile)
		cout << "Error opening the output file " << endl;

	//read operations from the input file
	string op;
	int x;
	while(inputFile >> op)
	{
		if (op == "insert")
		{
			inputFile >> x; // read the value x for insert
			tree.insert(x);
			//cout << "Inserted " << x << endl;
			//tree.displayInOrder();
			//cout << endl;
		}
		if (op == "remove")
		{
			inputFile >> x; // read the value x for remove 
			tree.remove(x);
			//cout << "Deleted " << x << endl;
			//tree.displayInOrder();
			//cout << endl;
		}
		if (op == "search")
		{
			inputFile >> x;
			if (tree.search(x) == true)
			{
				cout << "The key " << x << " is in the current tree.\n";
				outputFile << "The key " << x << " is in the current tree.\n";
			}
			else// x is not in the tree
			{
				cout << "The key " << x << " is not in the current tree.\n";
				outputFile << "The key " << x << " is not in the current tree.\n";
			}
		}
		if (op == "findMin")
		{
			cout << "The smallest key in the current tree is " << tree.findMin() << endl;
			outputFile << "The smallest key in the current tree is " << tree.findMin() << endl;
		}
	}

	//print the pre-odrder traversal to both screen and the outputfile
	cout << "The pre-order traversal list is: " << endl;
	outputFile << "The pre-order traversal list is: " << endl;
	tree.displayPreOrder();
	cout << endl;
	outputFile << endl;

	//print the in-odrder traversal to both screen and the outputfile
	cout << "The in-order traversal list is: " << endl;
	outputFile << "The in-order traversal list is: " << endl;
	tree.displayInOrder();
	cout << endl << endl;
	//outputFile << endl;

	//inputFile.close();
	//outputFile.close();

	return 0;
}
