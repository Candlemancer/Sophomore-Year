#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct Vertex
{
	int id;//the id of the vertex
	Vertex * next;
	Vertex(int id_input, Vertex * input_next = NULL)
	{
		id = id_input;
		next = input_next;
	}
};

class Graph
{
	public:
		int n;							//the number of vertices, the ids of the vertices [0, n-1]  
		Vertex ** adj;					//adj[i] points the head of the adjacency list of vertex i
		int* color;						//array to hold visitaiton info for each vertex
		stack<int> results;				//stack of results

		void topSort();					//do topological sort
		void topSortR(int id); 			// Recursive function for topSort

		Graph(int n_input);				//constructor
		void setAdjLists(int * adjM);	//build the adjacency lists from the adecency matrix adjM
		void printAdjLists();			//print the adjacency lists of the graph
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750
// Weighted Graphs

void Graph::topSort() {
	
	for (int i = 0; i < n; ++i)
	{
		// If node is unvisited
		if (color[i] != 2) {
				topSortR(i);
		}
	}

	// Print out he results stack.
	while (results.empty() == false) {
		cout << results.top() << " ";
		results.pop();
	}

	cout << endl;

	return;
}

// Recursive function to add the verticies to the stack.
void Graph::topSortR(int id) {
	
	// Mark current vertex as partially visited
	color[id] = 1;

	// Traverse adj to find the tree
	for (Vertex* neighbor = adj[id]; neighbor != NULL; neighbor = neighbor->next) {

		// Visit all unvisited neighbors
		if (color[neighbor->id] == 0) {
			topSortR(neighbor->id);
			color[neighbor->id] = 2;
		}
	
	}

	results.push(id);

	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Graph::Graph(int n_input)
{
	n = n_input;
	adj = new Vertex* [n];
	color = new int [n];

	//initialize adj[i] to NULL
	for(int i = 0; i < n; i++) {
		adj[i] = NULL;
		color[i] = 0;
	}


}


//construct the adj lists from the adj matrix adjM
void Graph::setAdjLists(int * adjM)
{
	for(int i = 0; i < n; i++)
	{
		//create the i-th adj list adj[i], note that I consider the
		//vertices in the reverse order from n-1 to 0 so that I can
		//construct the list in order from 0 to n-1 because a new
		//vertex is always inserted to the front
		for(int j = n-1; j >= 0; j--)
		{
			if(adjM[i * n + j] == 1)
			{
				//create a new node and add it to the front of adj[i]
				Vertex * v = new Vertex (j);
				v->next = adj[i];
				adj[i] = v;
			}
		}
	}
}

//print the adj lists
void Graph::printAdjLists()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Adj list of vertex " << i << ": "; 
		Vertex *v = adj[i];
		while(v != NULL)
		{
			if (v->next != NULL)
				cout << v->id << "->";
			else
				cout << v->id;
			v = v->next;
		}
		cout << endl;
	}

	cout << endl;
}


int main()
{
	//open files
	ifstream inputFile;
	inputFile.open("hw9_Q1_input.txt");
	if (!inputFile)
		cout << "Error opening the input file " << endl;
	
	int n;
	//read the number in the first line, which is the number of vertices of
	//the input graph
	inputFile >> n;

	cout << "The number of vertices is: " << n << endl;

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

	//uncomment the following line if you want to print the adj lists
	graph.printAdjLists();

	cout << "The following is a topological order:" << endl;
	graph.topSort();

	cout << endl;

	return 0;
}
