// Jonathan Petersen
// A01236750
// Roman Numeral Validator
// Driver Code
// Stretch Goal: Few Lines of Code

#include <algorithm>
#include <iostream>
#include <string>
#include "RomanNumeral.hpp"

using namespace std;

int main() {

	string input;

	//Input Primer
	cout << "Please input a Roman Numeral to be Validated, or QUIT to exit.\n";
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), toupper());

	while (input != "QUIT") {

		RomanNumeral myNumeral(input);

		//Error Checking
		if (myNumeral.getValue() == -1) cout << "Invalid" << endl;
		if (myNumeral.getValue() != -1) cout << "Validated! Value: " << myNumeral.getValue() << endl;

		//Input Loop
		cout << "Please input a Roman Numeral to be Validated, or QUIT to exit.\n";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), toupper);

	}

	cin.get();
	return 0;
}
