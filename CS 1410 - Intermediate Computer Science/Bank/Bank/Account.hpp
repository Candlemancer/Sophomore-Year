// Jonathan Petersen
// A01236750
// Bank Assignment
// Account Class Header

#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include <string>

using namespace std;

class Account {

public:
	Account();
	Account(int, double, double, string);

	virtual void transaction(double) = 0;
	virtual void update() = 0;

	int getAccountNum() const;
	double getBalance() const;
	double getUpdateRate() const;
	string getName() const;
	string getMessage() const;

protected:
	int accountNum;
	double balance;
	double updateRate;
	string name;
	string message;
};

ostream& operator<< (ostream& os, const Account& that);

#endif
