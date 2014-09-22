// Jonathan Petersen
// A01236750
// Graphs - BFE DFE

#include <iostream>
#include <fstream>
#include "hw8_Q5_Graph.hpp"
using namespace std;

int main()
{
	ifstream inputFile;
	inputFile.open("hw8_Q5_input.txt");
	if (!inputFile)
		cout << "Error opening the input file " << endl;
	
	int n;
	//read the number in the first line, which is the number of vertices of
	//the input graph
	inputFile >> n;
	//cout << "The number of vertices is: " << n << endl;

	//next we read the adjacency matrix from the file to an array M.
	//Here we use a one-dimensional array to simulate a two-dimesional
	//adjacency matrix because we already know the length of each row
	//is n
	int * M = new int [n * n];
	int i = 0;
	int value;
	while(inputFile >> value)
	{
		M[i] = value;
		i++;
	}
	inputFile.close();

	//uncomment the following piece of code if you want to check
	//whether the adj matrix is read correctly from the input file
	/*
	cout << "The following is the matrix:" << endl;
	for(int i = 0; i < n * n; i++)
	{
		if(i % n == 0)
			cout << endl;
		cout << M[i] << " ";
	}
	cout << endl;
	*/

	//initialize the graph by passing n to it
	Graph graph(n);
	graph.setAdjLists(M);
	graph.traverse();
	graph.printTraversed();
	cout << endl;
 
	for (int i = 1; i < n; i++) {
		graph.printShortestPath(i);
	}


	//uncomment the following line if you want to print the adj lists
	//graph.printAdjLists();

	return 0;
}

