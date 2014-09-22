// Jonathan Petersen
// A01236750
// String Parsing
// Driver Code

#include <iostream>
#include "StringParser.hpp"

using namespace std;

int main() {

	StringParser* parse;
	string input = "";

	cout << "Input a string: " << endl;
	
	while (input == "") {
		getline(std::cin, input);
	}

	while (input[0] != 'Q' && input[0] != 'q') {

	if (input != "") {
		parse = new StringParser(input);
		parse->print();
		delete parse;
	}

	cout << "Input a string: " << endl;
	getline(std::cin, input);

	}

	std::cin.get();
	return 0;
}

