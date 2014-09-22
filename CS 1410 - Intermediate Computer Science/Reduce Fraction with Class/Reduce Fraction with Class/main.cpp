//Jonathan Petersen
//A01236750
//Reduce a fraction using a struct.
//Driver code

#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	//Variable Declaration
	Fraction* myFraction;
	string input = "";

	//We need the input before we decide to break, so this check is always true.
	while (true) {

		cout << "Please enter a fraction to be reduced [ X/Y ], or [ Q ] to quit: ";
		cin >> input;

		//Avoid code duplication of prompt.
		if (input == "Q" || input == "q" || input == "quit" || input == "Quit") break;

		myFraction = new Fraction(input);

		if (myFraction->getDenominator() != 0) {		
			myFraction->simplify();
			cout << myFraction->getOutput() << endl;	
		}

		delete myFraction;
		
	}

	return 0;
}

