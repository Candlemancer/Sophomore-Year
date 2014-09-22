// Jonathan Petersen
// A01236750
// Fraction Calculator
// Driver Code

#include <iostream>
#include "Expression.hpp"
#include "Fraction.hpp"

using namespace std;

int main() {

	string input = "";

	cout << "Enter an expression of fractions [A/B+C/D] or quit to exit." << endl;
	getline(cin, input);

	while (input != "quit" 	&&
		   input != "Quit" 	&&
		   input != "QUIT" 	&&
		   input != "Q" 	&&
		   input != "q"		) {

		try {
	
			Expression* myExpression = new Expression(input);
			cout << (myExpression->calculate()).getOutput() << endl; 
			delete myExpression;

		}
		catch(Fraction::DivideByZero) {
	
			cout << "One of your fractions is dividing by zero. Please try again." << endl;
			getline(cin, input);
			continue;			
	
		}
		catch(Fraction::InvalidFraction) {

			cout << "Your expression is invalid. Please try again." << endl;
			getline(cin, input);
			continue;

		}

		getline(cin, input);
		
	}

	system("pause");
	return 0;
}
