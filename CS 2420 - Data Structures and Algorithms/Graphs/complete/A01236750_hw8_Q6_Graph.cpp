// Jonathan Petersen
// A01236750
// Graphs - BFS DFS
// Graph class implementation

#include "hw8_Q6_Graph.hpp"

//initialize the graph by getting the number of vertices from n_input
Graph::Graph(int n_input)
{

	n = n_input;
	adj = new Vertex * [n];
	//initialize adj[i] to NULL
	for(int i = 0; i < n; i++)
		adj[i] = NULL;

	// Initialize Color
	color = new colorType[n];
	for (int i = 0; i < n; ++i) {
		color[i] = white;
	}

	// Initialize the pre array
	pre = new int[n];
	for (int i = 0; i < n; ++i) {
		pre[i] = -1;
	}

	// Initiallize the distance array
	dis = new int[n];

}

Graph::~Graph() {

	delete[] color;
	delete[] pre;
	delete[] dis;

	for (int i = 0; i < n; ++i)
	{
		if (adj[i] != NULL) {
			delete adj[i];
		}
	}

	delete[] adj;


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

void Graph::traverse(int start) {

	cout << "The following is the DFS traversal vertex order, staring from vertex 0:" << endl;

	for (int i = start; i < n; ++i)
	{
		if (color[i] != red) {
				rTraverse(i);
		}
	}



	cout << endl;

	return;
}

void Graph::rTraverse(int id) {

	cout << id << " ";

	// Traverse adj to find the tree
	for (Vertex* neighbor = adj[id]; neighbor != NULL; neighbor = neighbor->next) {

		if (color[neighbor->id] == white) {
			color[neighbor->id] = blue;
			rTraverse(neighbor->id);
			color[neighbor->id] = red;
		}

	}

	return;
}







