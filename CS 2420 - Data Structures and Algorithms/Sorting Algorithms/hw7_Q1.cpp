#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750

//sort all numbers in A[0,...,n-1]
void bubbleSort(int A[], int n) {

	for (int pass = 0; pass <= n; pass++) {

		for (int i = 1; i < n - pass; i++) {

			if ( A[i] < A[i-1] ) { 
				swap(A[i], A[i-1]);
			}

		}

	}

	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	//open files
	ifstream inputFile;
	inputFile.open("hw7_input.txt");
	if (!inputFile)
		cout << "Error opening the input file " << endl;
	
	int A[100];
	int value;
	int n = 0;

	//read numbers from the input file, after the while loop all
	//numbers are stored in A[0,...,n-1], i.e., n is the number of
	//elements in A
	while(inputFile >> value)
	{
		A[n] = value;
		n++;
	}

	//call bubble sort
	bubbleSort(A, n);

	cout << "The following is the list after bubble sort:" << endl;
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;

	inputFile.close();
	return 0;
}
