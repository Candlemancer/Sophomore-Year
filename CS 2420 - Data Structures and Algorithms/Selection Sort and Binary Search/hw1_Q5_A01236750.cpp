#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 100;

void input(int A[], int & n, const string & fileName) 
{
	ifstream inputFile;
	int value;

	inputFile.open(fileName.c_str());

	//read data until the end of the file
	while(inputFile >> value)
	{
		A[n] = value;
		n++;
	}

	inputFile.close();
}

void output(int A[], const int n, const string & fileName) 
{
	ofstream outputFile;
	outputFile.open(fileName.c_str());
	for (int i = 0; i < n; i++)
	  	 outputFile << A[i] << "  "; 
	 
	outputFile.close();
}

//please complete the following function
void selectionSort(int A[], int n)
{
///////////////////////////////////////////////////////////////////////////////
	// Jonathan Petersen
	// A01236750
	// Selection Sort Algorithm

	int smallestIndex = 0;
	// Leave the last element off since a list of (the last) one is sorted.
	for (int i = 0; i < n - 1; i++) {
		
		// Make sure to start after the current element, or you'll loop.
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[smallestIndex]) smallestIndex = j;
		}

		if(A[smallestIndex] < A[i]) std::swap(A[smallestIndex], A[i]);

	}

	return;
///////////////////////////////////////////////////////////////////////////////
}

int main()
{
	int A[ARRAY_SIZE];
	int n = 0;// the number of elements stored in A
	string inputFile = "hw1_Q5_input.txt"; // the name of the input file 
	string outputFile = "hw1_Q5_output.txt"; // the name of the output file 

	//read the numbers from the input file to array A
	input(A, n, inputFile); 

	selectionSort(A, n); 

	/*
	for (int i = 0; i < n; i++)
		cout << A[i] << "  "; 
	*/

	//output the sorted numbers in A to output file
	output(A, n, outputFile);

	return 0;
}
