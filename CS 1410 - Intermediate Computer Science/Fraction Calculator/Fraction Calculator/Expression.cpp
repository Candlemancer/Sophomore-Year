//Jonathan Petersen
//A01236750
//Fraction Calculator
//Expression Class Implementation

#include "Expression.hpp"
#include "Fraction.hpp"
#include <string>
#include <regex>

using namespace std;

//Default Constructor
Expression::Expression() :
	lhs(new Fraction("0/1")),
	operation("_"),
	rhs(new Fraction("0/1")) {

}

//Parameter Constructor
Expression::Expression(string input) {

	regex fraction("([\\+-]?\\d+)/([\\+-]?\\d+)");
	regex operations("[\\+\\-\\*\\/]");
	smatch match;

	if (!regex_search(input, match, fraction, regex_constants::match_continuous)){ 
		lhs = new Fraction("ERROR"); 
	}
	else {
		lhs = new Fraction(match[0]);
		input = input.substr(match[0].length(), input.length() - match[0].length());
	}

	if (!regex_search(input, match, operations, regex_constants::match_continuous)) { 
		operation = "_"; 
	}
	else {
		operation = match[0];
		input = input.substr(match[0].length(), input.length() - match[0].length());
	}

	if (!regex_search(input, match, fraction, regex_constants::match_continuous)) { 
		rhs = new Fraction("ERROR"); 
	}
	else {
		rhs = new Fraction(match[0]);
		input = input.substr(match[0].length(), input.length() - match[0].length());
	}

}

//Copy Constructor
Expression::Expression(const Expression& that) :
	lhs(new Fraction(that.getLhs())),
	operation(that.getOperation()),
	rhs(new Fraction(that.getRhs())){

}

//Destructor
Expression::~Expression() {

	delete lhs;
	delete rhs;

}

//Function to get the left operand
Fraction Expression::getLhs() const { return *lhs; }

//Function to get the right operand
Fraction Expression::getRhs() const { return *rhs; }

//Function to get the operator
string Expression::getOperation() const { return operation; }

//Calcluate the result
Fraction Expression::calculate() {

	switch(operation[0]) {

		case '+':
			result = new Fraction( 
					to_string(lhs->getNumerator() * rhs->getDenominator() 
							+ rhs->getNumerator() * lhs->getDenominator()) 
					+ "/" + 
					to_string(lhs->getDenominator() * rhs->getDenominator()) 
				);
			break;

		case '-':
			result = new Fraction( 
					to_string(lhs->getNumerator() * rhs->getDenominator() 
							- rhs->getNumerator() * lhs->getDenominator()) 
					+ "/" + 
					to_string(lhs->getDenominator() * rhs->getDenominator()) 
				);
			break;

		case '*':
			result = new Fraction( 
					to_string(lhs->getNumerator() * rhs->getNumerator())
					+ "/" +
					to_string(lhs->getDenominator() * rhs->getDenominator())
				);
			break;

		case '/':
			result = new Fraction( 
					to_string(lhs->getNumerator() * rhs->getDenominator())
					+ "/" +
					to_string(lhs->getDenominator() * rhs->getNumerator())
				);
			break;

		default:
			result = new Fraction("ERROR"); 

	}

	return *result;

}

//Swap function for copy/swap
void swap(Expression& first, Expression& second) {

	// Enable ADL
	using std::swap; 

	swap(first.lhs, second.lhs);
	swap(first.operation, second.operation);
	swap(first.rhs, second.rhs);

}

Expression& Expression::operator=(Expression that) {

	swap(*this, that);
	return *this;

}
