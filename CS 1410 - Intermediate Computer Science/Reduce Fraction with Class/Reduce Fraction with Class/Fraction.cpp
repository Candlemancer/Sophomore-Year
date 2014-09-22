// Jonathan Petersen
// A01236750
// Reduce a fraction using a class
// Fraction class implementation

#include "Fraction.h"
#include <iostream>
#include <string>
#include <regex>


//Default Constructor
Fraction::Fraction() 
	: numerator(0),
	  denominator(0) {}

//Build a fraction struct with validated user input
Fraction::Fraction(const string& input) 
	: numerator(0),
	  denominator(0) {

	//Variable definitions
	regex pattern("([\\+-]?\\d+)/{1}([\\+-]?\\d+)");
	smatch numbers;

	if ( !regex_match(input, numbers, pattern) ) { cout << "Invalid fraction format.\n"; return;}

	//Assign the appropriate matches to the fraction object
	numerator = stoi(numbers[1]);
	denominator = stoi(numbers[2]);

	if ( denominator == 0 ) { cout << "Cannot divide by 0.\n"; return;}

	return;
}

//Default Destructor
Fraction::~Fraction() {}

//Print out a fraction struct
string Fraction::getOutput() {

	return ((to_string(numerator) += "/") += to_string(denominator));

}

//Reduce a fraction to simplest terms
void Fraction::simplify() {

	int divisor = 1;

	//Since we want the output to include the original denominator if numerator is 0.
	if (numerator != 0) { divisor = gcd(numerator, denominator); }
	numerator /= divisor;
	denominator /= divisor;
	if (denominator < 0) { numerator *= -1; denominator *= -1; }

	return;
}

//Find the greatest common divisor recursively
int Fraction::gcd(int x, int y) {

	//Base Case
	if (y == 0) return x;

	//Alternate Case
	return gcd(y, x % y);

}

//Getters for Fraction
int Fraction::getNumerator() { return numerator; }
int Fraction::getDenominator() { return denominator; }
