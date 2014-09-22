// Jonathan Petersen
// A01236750
// Graphs - BFS DFS
// Graph Class Header
#ifndef HW8_Q5_GRAPH_HPP
#define HW8_Q5_GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum colorType {white, blue, red};

struct Vertex {
	int id;//the id of the vertex
	Vertex* next;
	Vertex(int id_input, Vertex * input_next = NULL) {
		id = id_input;
		next = input_next;
	}
};

class Graph {
	private:

		vector<int> traversed;
		int* visited; // 0 if unvisited, 1 if visited
		int* pre; // record the predecessors during BFS
		// int* dis; // record the shortest path distances during BFS


	public:
		int n;//the number of vertices, the ids of the vertices are from 0 to n-1  
		Vertex ** adj;//adj[i] points the head of the adjacency list of vertex i, for i from 0 to n-1

		Graph(int n_input);//constructor

		void setAdjLists(int * adjM);//build the adjacency lists from the adecency matrix adjM
		void printAdjLists();//print the adjacency lists of the graph
		// void printSP(int source, int v);//print shortest path from the source to v

		void traverse(int = 0); // Return a vector containing the verticies in traversal order
		void printTraversed(); // Prints the traversed vector.
		void printShortestPath(int id); // Prints the shrotest path from id based on traversed.

};

#endif // HW8_Q5_GRAPH_HPP