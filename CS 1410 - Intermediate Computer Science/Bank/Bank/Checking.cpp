// Jonathan Petersen
// A01236750
// Bank Assignment
// Checking Account Class Implementation

#include "Checking.hpp"
#include <iostream>

Checking::Checking() : 
	Account(), 
	numChecks(0) {}

Checking::Checking(int newAccountNum, double  newBalance, double newUpdateRate, string newName) :
	Account(newAccountNum, newBalance, newUpdateRate, newName),
	numChecks(0) {}

void Checking::transaction(double amount) {

	//If we're writing a check, increment check count;
	if(amount < 0) numChecks++;

	//Check if check has bounced
	if(amount < 0 && balance + amount < 0) {
		balance -= checkFee;
		printf("%s (checking): $%.2f rejected (insufficient funds)\n", name.c_str(), amount);
		printf("%s (checking): $%.2f applied to account\n", name.c_str(), (checkFee * -1.0));
		printf("%s (checking): balance is $%.2f", name.c_str(), balance);
		return;
	}

	//Or Adjust the amount accordingly
	balance += amount;

	printf("%s (checking): $%.2f applied to account\n", name.c_str(), amount);
	printf("%s (checking): balance is $%.2f", name.c_str(), balance);
	return;
}

void Checking::update() {

	double amount = numChecks * updateRate;
	balance -= amount;

	printf("%s (checking): $%.2f applied to account\n", name.c_str(), -amount);
	printf("%s (checking): balance is $%.2f", name.c_str(), balance);
	numChecks = 0;
	return;
}

ostream& operator<< (ostream& os, const Checking& that) {

	printf("%s (checking): balance is $%.2f", that.getName().c_str(), that.getBalance());
	return os;
}
