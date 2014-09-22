// Jonathan Petersen
// A01236750
// Reduce a fraction using a class
// Fraction class implementation

#include "Fraction.hpp"
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

	validate(input);
	simplify();

	return;
}

//Copy Constructor
Fraction::Fraction(const Fraction& that) :
	numerator(that.getNumerator()),
	denominator(that.getDenominator()) {
}

//Default Destructor
Fraction::~Fraction() {}

/*
//Print out a fraction struct
string Fraction::getOutput() {

	return ((to_string(numerator) += "/") += to_string(denominator));

}
*/

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

//Validate that a fraction is in the proper format
void Fraction::validate(const string& input) {

	//Variable definitions
	regex pattern("([\\+-]?\\d+)/([\\+-]?\\d+)");
	smatch numbers;

	if ( !regex_match(input, numbers, pattern) ) { throw InvalidFraction(); }

	numerator = stoi(numbers[1]);
	denominator = stoi(numbers[2]);

	if ( denominator == 0 ) { throw DivideByZero(); }

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
int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

Fraction Fraction::operator+=(const Fraction& that) {

	numerator = (this->numerator * that.getDenominator()) 
			  + (that.getNumerator() * this->denominator);
	denominator = this->denominator * that.getDenominator();

	simplify();
	return *this;
}

Fraction Fraction::operator-=(const Fraction& that) {

	numerator = (this->numerator * that.getDenominator()) 
			  - (that.getNumerator() * this->denominator);
	denominator = this->denominator * that.getDenominator();

	simplify();
	return *this;
}

Fraction Fraction::operator*=(const Fraction& that) {

	numerator = this->numerator * that.getNumerator();
	denominator = this->denominator * that.getDenominator();

	simplify();
	return *this;
}

Fraction Fraction::operator/=(const Fraction& that) {

	numerator = this->numerator * that.getDenominator();
	denominator = this->denominator * that.getNumerator();

	simplify();
	return *this;
}

Fraction operator+(Fraction lhs, const Fraction& rhs) {

	lhs += rhs;
	return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {

	lhs -= rhs;
	return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {

	lhs *= rhs;
	return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {

	lhs /= rhs;
	return lhs;
}

ostream& operator<<(ostream& out, const Fraction& that){

	out << to_string(that.getNumerator()) << "/" << to_string(that.getDenominator());
	return out;

}
