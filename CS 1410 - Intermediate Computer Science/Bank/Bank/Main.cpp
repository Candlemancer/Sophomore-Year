// Jonathan Petersen
// A01236750
// Bank Assignment
// Driver Code

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Account.hpp"
#include "Checking.hpp"
#include "Savings.hpp"
#include "Loan.hpp"

using namespace std;

int main() {

	ifstream fin("Input.txt");
	string currentLine;
	stringstream ss;

	typedef unordered_map<int, Account*> accountMap;
	accountMap bank;

	int tempAccountNum;
	double tempBalance;
	double tempUpdateRate;
	string tempName;

	while (!fin.eof()) {

		getline(fin, currentLine);
		ss.str(currentLine);

		switch (ss.get()) {

			case 's':
			cout << "new account..." << endl;
			ss >> tempAccountNum;
			ss >> tempName;
			ss >> tempBalance;
			ss >> tempUpdateRate;
			bank.emplace(tempAccountNum, new Savings(tempAccountNum, tempBalance, tempUpdateRate, tempName));
			cout << *dynamic_cast<Savings*>(bank[tempAccountNum]);
			break;

			case 'c':
			cout << "new account..." << endl;
			ss >> tempAccountNum;
			ss >> tempName;
			ss >> tempBalance;
			ss >> tempUpdateRate;
			bank.emplace(tempAccountNum, new Checking(tempAccountNum, tempBalance, tempUpdateRate, tempName));
			cout << *dynamic_cast<Checking*>(bank[tempAccountNum]);
			break;

			case 'l':
			cout << "new account..." << endl;
			ss >> tempAccountNum;
			ss >> tempName;
			ss >> tempBalance;
			ss >> tempUpdateRate;
			bank.emplace(tempAccountNum, new Loan(tempAccountNum, tempBalance, tempUpdateRate, tempName));
			cout << *dynamic_cast<Loan*>(bank[tempAccountNum]);
			break;

			case 't':
			cout << "transaction..." << endl;
			ss >> tempAccountNum;
			ss >> tempBalance;
			bank[tempAccountNum]->transaction(tempBalance);
			break;

			case 'u':
			cout << "update..." << endl;
			ss >> tempAccountNum;
			bank[tempAccountNum]->update();
			break;

			default:
			cout << "Unknown symbol. Skipping line." << endl;
			break;

		}
		ss.clear();
		cout << endl << endl;

	}

	for (accountMap::iterator it = bank.begin(); it != bank.end(); it++) {
		delete it->second;
	}

	cin.get();
	return 0;
}
