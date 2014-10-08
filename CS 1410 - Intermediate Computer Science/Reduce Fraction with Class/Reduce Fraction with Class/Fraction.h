// Jonathan Petersen
// A01236750
// Reduce a fraction using a class
// Fraction class header

#ifndef _FRACTION_H
#define _FRACTION_H

#include <string>

using namespace std;

class Fraction {

	public:
		//Constructors
		Fraction();
		Fraction(const string&);
		~Fraction();

		//Methods
		string getOutput();
		void simplify();
		int  getNumerator();
		int  getDenominator();

	private:
		int  gcd(int, int);

		//Data
		int numerator;
		int denominator;

};

#endif
