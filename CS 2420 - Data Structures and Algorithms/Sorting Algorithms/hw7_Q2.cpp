#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750

//merge the two sorted subarrays A[low,...,mid] and A[mid+1,...,high]
void merge(int A[], int low, int mid, int high) {

	int less[mid - low + 2];
	int more[high - mid + 1];

	// Fill out the buffers with infinity termination
	for (int i = 0; i < (mid - low + 1); i++) {
		less[i] = A[low + i];
	}
	less[mid - low + 1] = numeric_limits<int>::max();

	for (int i = 0; i < (high - mid); i++) {
		more[i] = A[mid + 1 + i];
	}
	more[high - mid] = numeric_limits<int>::max();

	// Merge the buffers
	int i = 0;
	int j = 0;
	for (int k = low; k <= high; k++) {
		if (less[i] < more[j]) {
			A[k] = less[i];
			i++;
		}
		else {
			A[k] = more[j];
			j++;
		}
	}

}

//sort all numbers in A[low,...,high]
void mergeSort(int A[], int low, int high) {

	// Base Case
	if (high - low <= 0) { return; } // An set of 1 element is sorted.

	// Recursive Case
	int mid = low + (high - low) / 2;
	mergeSort(A, low, mid);
	mergeSort(A, mid + 1, high);

	merge(A, low, mid, high);

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

	mergeSort(A, 0, n-1);

	cout << "The following is the list after mergesort:" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	
	cout << endl;

	inputFile.close();
	return 0;
}
