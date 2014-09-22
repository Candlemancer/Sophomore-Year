// Jonathan Petersen
// A01236750
// Bank Assignment
// Savings Account Class Implementation

#include "Savings.hpp"

Savings::Savings() : 
	Account() {}

Savings::Savings(int newAccountNum, double  newBalance, double newUpdateRate, string newName) :
	Account(newAccountNum, newBalance, newUpdateRate, newName) {}

void Savings::transaction(double amount) {

	//Check for insufficient funds
	if(amount < 0 && balance + amount < 0) {
		printf("%s (savings): $%.2f rejected (insufficient funds)\n", name.c_str(), amount);
		printf("%s (savings): balance is $%.2f", name.c_str(), balance);
		return;
	}

	//Or Adjust the amount accordingly
	balance += amount;

	printf("%s (savings): $%.2f applied to account\n", name.c_str(), amount);
	printf("%s (savings): balance is $%.2f", name.c_str(), balance);
	return;
}

void Savings::update() {

	double amount = balance * updateRate;
	balance += amount;

	printf("%s (savings): $%.2f applied to account\n", name.c_str(), amount);
	printf("%s (savings): balance is $%.2f", name.c_str(), balance);
	return;
}

ostream& operator<< (ostream& os, const Savings& that) {

	printf("%s (savings): balance is $%.2f", that.getName().c_str(), that.getBalance());
	return os;
}
