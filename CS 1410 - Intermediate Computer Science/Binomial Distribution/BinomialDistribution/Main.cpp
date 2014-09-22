// Jonathan Petersen
// A01236750
// Binomial Distribution
// Driver Code

#include <iostream>
#include <ctime>
#include "Tree.hpp"

using namespace std;

int main() {

	srand(static_cast<int>(time(NULL)));

	Tree myTree(256);
	Tree yourTree(256);
	Tree ourTree(256);

	cout << myTree << endl;
	cout << yourTree << endl;
	cout << ourTree << endl;


	cin.get();
	return 0;
}
