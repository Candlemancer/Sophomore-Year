// Jonathan Petersen
// A01236750
// Roman Numeral Validator
// Roman Numeral Class Definition

#ifndef _ROMAN_NUMERAL_H
#define _ROMAN_NUMERAL_H

#include <string>

using namespace std;

class RomanNumeral {

public:
	//Constructors
	RomanNumeral(string);
	inline string getNumeral() { return numeral; }
	inline int getValue() { return value; }

private:
	bool validate();
	void compute();

	string numeral;
	int value;

};

#endif
