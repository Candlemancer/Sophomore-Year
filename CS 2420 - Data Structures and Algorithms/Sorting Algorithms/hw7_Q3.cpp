#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750

//partition A[low,...,high] into two subarrays by using a pivot, and
//return the index of the pivot in the resulting partition
int partition(int A[], int low, int high) {

	// Select a pivot. Let's go with Middle Pivot because we can.
	int idx_pivot = low + (high - low) / 2;
	int val_pivot = A[idx_pivot];

	// Get the pivot out of the way
	swap(A[high], A[idx_pivot]);
	idx_pivot = high;

	// Get the lower numbers on the left
	int idx_mid = low;

	for (int i = low; i < high; i++) {
		if (A[i] < val_pivot) {
			swap(A[i], A[idx_mid]);
			idx_mid++;
		}
	}

	// Restore pivot
	swap(A[idx_mid], A[idx_pivot]);

	return idx_mid;
}

//sort the elements in A[low,...,high]
void quickSort(int A[], int low, int high) {

	// Base Case
	if (high - low <= 0) return;

	// Recursive Case
	int pivot = partition(A, low, high);
	quickSort(A, low, pivot - 1);
	quickSort(A, pivot + 1, high);

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

	//call quicksort
	quickSort(A, 0, n-1);

	cout << "The following is the list after quick sort:" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}
