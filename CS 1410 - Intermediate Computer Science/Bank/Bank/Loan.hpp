// Jonathan Petersen
// A01236750
// Bank Assignment
// Loan Account Class Header

#ifndef __LOAN_H
#define __LOAN_H

#include <string>
#include "Account.hpp"

using namespace std;

class Loan : public Account {

public:
	Loan();
	Loan(int, double, double, string);

	void transaction(double);
	void update();

};

ostream& operator<< (ostream& os, const Loan& that);

#endif
