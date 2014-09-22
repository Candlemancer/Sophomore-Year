// Jonathan Petersen
// A01236750
// Bank Assignment
// Account Class Implementation

#include "Account.hpp"

using namespace std;

Account::Account() :
	accountNum(-1),
	balance(0),
	updateRate(0),
	name("Unknown"),
	message("") {}

Account::Account(int newAccountNum, double  newBalance, double newUpdateRate, string newName) :
	accountNum(newAccountNum),
	balance(newBalance),
	updateRate(newUpdateRate),
	name(newName),
	message("") {}

int Account::getAccountNum() 	const { return accountNum; }
double Account::getBalance() 	const { return balance; }
double Account::getUpdateRate() const { return updateRate; }
string Account::getName() 		const { return name; }
string Account::getMessage()	const { return message; }

// void Account::transaction(double amount) {printf("Performed Transaction on %i for $%.2f", accountNum, amount);}

// void Account::update() { printf("Updating %i", accountNum); }

ostream& operator<< (ostream& os, const Account& that) {

	os << that.getName() << " (" << typeid(that).name() << "): balance is $" << that.getBalance();
	return os;
}
