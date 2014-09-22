// Jonathan Petersen
// A01236750
// Graphs - BFS DFS 
// Graph Class Header

#ifndef HW8_Q6_GRAPH_HPP
#define HW8_Q6_GRAPH_HPP

#include <iostream>

using namespace std;

enum colorType {white, blue, red};

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
	private:
		colorType* color;
		int* pre;
		int* dis;

	public:
		int n;//the number of vertices, the ids of the vertices are from 0 to n-1  
		Vertex ** adj;//adj[i] points the head of the adjacency list of vertex i

		Graph(int n_input);//constructor
		~Graph(); // Destructor
		void setAdjLists(int * adjM);//build the adjacency lists from the adecency matrix adjM
		void printAdjLists();//print the adjacency lists of the graph
		void printSP(int source, int v);//print shortest path from the source to v

		void traverse(int start = 0); 
		void rTraverse(int id);
};

#endif // HW8_Q6_GRAPH_HPP