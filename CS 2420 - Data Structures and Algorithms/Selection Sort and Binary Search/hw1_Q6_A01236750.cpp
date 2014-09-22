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

// Please complete the following function. If the search value x is in the array, then return the index of x in the array; 
// otherwise return -1. first is the first index and last is the last index of the portion of the array you want to search 
// for x; x is the number you want to search in the array
int binarySearch(int array[], int first, int last, int x)
{
///////////////////////////////////////////////////////////////////////////////
	// Jonathan Petersen
	// A01236750
	// Binary Search Algorithm

	// Base Cases
	if(array[first] == x) return first;
	if(array[last] == x) return last;

	if(last - first < 1) return -1;

	// Alternative Case
	int mid = first + ((last - first) / 2);
	if(x <= array[mid]) return binarySearch(array, first, mid, x);
	return binarySearch(array, mid + 1, last, x);

///////////////////////////////////////////////////////////////////////////////
}

int main()
{
	int A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE];// array C is used to hold the search results temporarily
	int n = 0;// the number of elements stored in A
	int m = 0;// the number of elements stored in B
	string dataFile = "hw1_Q6_data.txt"; // the name of the data file 
	string searchFile = "hw1_Q6_search.txt"; // the name of the search file 
	string outputFile = "hw1_Q6_output.txt"; // the name of the output file 

	input(A, n, dataFile); 
	input(B, m, searchFile); 

	for (int i = 0; i < m; i++)
	{
		C[i] = binarySearch(A, 0, n-1, B[i]); 
		//cout << "The position of " << B[i] << " is " << C[i] << endl; 
	}

	output(C, m, outputFile);

	cout << endl; 
	
	return 0;
}
