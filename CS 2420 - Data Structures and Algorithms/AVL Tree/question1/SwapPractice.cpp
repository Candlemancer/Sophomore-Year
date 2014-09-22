// Jonathan Petersen
// A01236750
// Swap Practice

#include <iostream>

using namespace std;

int main() {

	int dancer = 21;
	int partner = 24;

	int* her = &dancer;
	int* him = &partner;

	cout << "She is " << *her << " years old." << endl;
	cout << "He is " << *him << " years old." << endl;

	swap(*her, *him);

	cout << "The dancer was 21. The dancer is now " << dancer << "." << endl;
	cout << "The partner was 24. The partner is now " << partner << "." << endl;

	return 0;
}