// Jonathan Petersen
// A01236750
// Binary Search Tree Assignment
// Driver Code

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "Tree.hpp"

using namespace std;

int main() {

	ifstream fin("input.txt");
	Tree myTree;
	string temp;

	regex digit("([0-9]+)");
	smatch matches;
	vector<int> myVector;
	
	getline(fin, temp);

	while(!fin.eof()) {

		while( regex_search(temp, matches, digit) ) {

			myVector.push_back(stoi(matches[0].str()));			
			temp = matches.suffix().str();

		}

		switch(myVector[0]) {

		case 1:
			for (int i=1; i<(int)myVector.size(); i++) {
				myTree.insert(myVector[i]);
			}
			break;

		case 2:
			for (int i=1; i<(int)myVector.size(); i++) {
				myTree.remove(myVector[i]);
			}
			break;

		case 3:
			myTree.find(myVector[1]);
			break;

		case 4:
			myTree.findMin();
			break;

		case 5:
			myTree.findMax();
			break;

		case 6:
			myTree.print();
			break;

		default:
			cout << "Unable to determine operator. Continuing." << endl;

		}

		myVector.clear();
		getline(fin, temp);

	}


	cin.get();
	return 0;
}
