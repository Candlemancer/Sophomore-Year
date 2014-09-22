//Jonathan Petersen
//A01236750
//Reduce a fraction using a struct.
//Stretch goal: Single Fraction object, robustness

#include <iostream>
#include <string>
#include <regex>

using namespace std;

//Hold a single fraction
struct Fraction {

	int numerator;
	int denominator;

};

//Function Prototypes
bool getFraction(Fraction&, const string&);
void putFraction(const Fraction&);
void simplify(Fraction&);
int  gcd(int, int);


int main() {

	//Variable Declaration
	Fraction myFraction;
	string input = "";

	//We need the input before we decide to break, so this check is always true.
	while (true) {

		cout << "Please enter a fraction to be reduced [ X/Y ], or [ Q ] to quit: ";
		cin >> input;

		//Avoid code duplication of prompt. One-Liner to permit breaking out of the loop.
		if (input == "Q" || input == "q" || input == "quit" || input == "Quit") break;

		if (getFraction(myFraction, input)) {		
			simplify(myFraction);
			putFraction(myFraction);	
		}
		
	}

	return 0;
}


//Build a fraction struct with validated user input
bool getFraction(Fraction& fract, const string& input) {

	//Variable definitions
	regex pattern("([\\+-]?\\d+)/{1}([\\+-]?\\d+)");
	smatch numbers;

	if ( !regex_match(input, numbers, pattern) ) { cout << "Invalid fraction format.\n"; return false;}

	//Assign the appropriate matches to the fraction object
	fract.numerator = stoi(numbers[1]);
	fract.denominator = stoi(numbers[2]);

	if ( fract.denominator == 0 ) { cout << "Cannot divide by 0.\n"; return false; }

	return true;
}

//Print out a fraction struct
void putFraction(const Fraction& fract) {

	cout << fract.numerator << "/" << fract.denominator << "\n";

	return;
}

//Reduce a fraction to simplest terms
void simplify(Fraction& fract) {

	int divisor = 1;

	//Since we want the output to include the original denominator if numerator is 0.
	if (fract.numerator != 0) { divisor = gcd(fract.numerator, fract.denominator); }
	fract.numerator /= divisor;
	fract.denominator /= divisor;

	return;
}

//Find the greatest common divisor recursively
int gcd(int x, int y) {

	//Base Case
	if (y == 0) return x;

	//Alternate Case
	gcd(y, x % y);

}