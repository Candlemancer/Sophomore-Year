// Jonathan Petersen
// A01236750
// Bank Assignment
// Savings Account Class Header

#ifndef __SAVINGS_H
#define __SAVINGS_H

#include <string>
#include "Account.hpp"

using namespace std;

class Savings : public Account {

public:
	Savings();
	Savings(int, double, double, string);

	void transaction(double);
	void update();

};

ostream& operator<< (ostream& os, const Savings& that);

#endif
