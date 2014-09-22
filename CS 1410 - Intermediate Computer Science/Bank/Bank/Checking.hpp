// Jonathan Petersen
// A01236750
// Bank Assignment
// Checking Account Class Header

#ifndef __CHECKING_H
#define __CHECKING_H

#include <string>
#include "Account.hpp"

using namespace std;

class Checking : public Account {

public:
	Checking();
	Checking(int, double, double, string);

	void transaction(double);
	void update();

	// int getCheckFee();

private:
	static const int checkFee = 25;
	int numChecks;

};

ostream& operator<< (ostream& os, const Checking& that);

#endif
