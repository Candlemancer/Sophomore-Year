// Jonathan Petersen
// A01236750
// Reduce a fraction using a class
// Fraction class header

#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <string>

using namespace std;

class Fraction {

	public:
		//Constructors
		Fraction();
		Fraction(const string&);
		Fraction(const Fraction&);
		~Fraction();

		//Methods
		string getOutput();
		int  getNumerator() const;
		int  getDenominator() const;
		//Fraction Invert();
		//Fraction Negate();

		class DivideByZero {};
		class InvalidFraction {};

	private:
		void validate(const string&);
		void simplify();
		int  gcd(int, int);

		//Data
		int numerator;
		int denominator;

};

#endif
