//Jonathan Petersen
//A01236750
//Fraction Calculator
//Expression Class Interface

#ifndef _EXPRESSION_HPP
#define _EXPRESSION_HPP

#include "Fraction.hpp"
#include <string>

using namespace std;

class Expression
{
public:
	//Constructors
	Expression();
	Expression(string);
	Expression(const Expression&);
	~Expression();

	//Methods
	Fraction getLhs() const;
	Fraction getRhs() const;
	string getOperation() const;

	Fraction calculate();

	Expression& operator=(Expression that);

private:
	friend void swap(Expression&, Expression&); //NOTE: This is a good use of friend. Trust me.

	Fraction* lhs;
	Fraction* rhs;
	Fraction* result;
	string operation;
};


#endif

