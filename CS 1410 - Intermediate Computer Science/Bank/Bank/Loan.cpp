// Jonathan Petersen
// A01236750
// Bank Assignment
// Loan Account Class Implementation

#include "Loan.hpp"

Loan::Loan() : 
	Account() {}

Loan::Loan(int newAccountNum, double  newBalance, double newUpdateRate, string newName) :
	Account(newAccountNum, -newBalance, newUpdateRate, newName) {}

void Loan::transaction(double amount) {

	balance += amount;

	printf("%s (loan): $%.2f applied to account\n", name.c_str(), amount);
	printf("%s (loan): balance is $%.2f", name.c_str(), balance);
	return;
}

void Loan::update() {

	double amount = balance * updateRate;
	balance += amount;

	printf("%s (loan): $%.2f applied to account\n", name.c_str(), amount);
	printf("%s (loan): balance is $%.2f", name.c_str(), balance);
	return;
}

ostream& operator<< (ostream& os, const Loan& that) {

	printf("%s (loan): balance is $%.2f", that.getName().c_str(), that.getBalance());
	return os;
}
