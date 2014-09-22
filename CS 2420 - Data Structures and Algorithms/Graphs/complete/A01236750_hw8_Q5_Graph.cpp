// Jonathan Petersen
// A01236750
// Graphs - BFS DFS

#include "hw8_Q5_Graph.hpp"

//initialize the graph by getting the number of vertices from n_input
Graph::Graph(int n_input) {
	n = n_input;
	adj = new Vertex * [n];
	//initialize adj[i] to NULL
	for(int i = 0; i < n; i++)
		adj[i] = NULL;
}

//construct the adj lists from the adj matrix adjM
void Graph::setAdjLists(int * adjM) {
	for(int i = 0; i < n; i++) {
		//create the i-th adj list adj[i], note that I consider the
		//vertices in the reverse order from n-1 to 0 so that I can
		//construct the list in order from 0 to n-1 because a new
		//vertex is always inserted to the front
		for(int j = n-1; j >= 0; j--) {
			if(adjM[i * n + j] == 1) {
				//create a new node and add it to the front of adj[i]
				Vertex * v = new Vertex (j);
				v->next = adj[i];
				adj[i] = v;
			}
		}
	}
}

//print the adj lists
void Graph::printAdjLists() {
	for(int i = 0; i < n; i++) {
		cout << "Adj list of vertex " << i << ": "; 
		Vertex *v = adj[i];
		while(v != NULL) {
			if (v->next != NULL) {
				cout << v->id << "->";
			}
			else {
				cout << v->id;
			}
			v = v->next;
		}
		cout << endl;
	}

	cout << endl;
}

// Return a vector containing the verticies in traversal order
void Graph::traverse(int index) {

	queue<Vertex*> toVisit;
	visited = new int[n];
	pre = new int[n];

	// Initialize 
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	toVisit.push(adj[index]);
	traversed.push_back(index);
	visited[index] = 1;

	while (toVisit.size() != 0) {

		// Add neighbors to adj list if unvisited
		for (Vertex* v = adj[index]; v != NULL; v = v->next) {
			
			if (visited[v->id] == 0) {
				pre[v->id] = index;
				toVisit.push(v);
				traversed.push_back(v->id);
				visited[v->id] = 1;

				// cout << "Added vertex " << v->id << " with pre " << pre[v->id] << endl;
			}


		}

		index = toVisit.front()->id;
		toVisit.pop();
	}

	return;
}

void Graph::printTraversed() {

	cout << "The following is the BFS traversal vertex order, staring from vertex 0:" << endl;
	for (vector<int>::const_iterator i = traversed.begin(); i != traversed.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	// cout << "The following is the pre array:" << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << pre[i] << " ";
	// }
	// cout << endl;

	return;
}

void Graph::printShortestPath(int id) {

	vector<int> result;

	for (int i = id; i != traversed[0]; i = pre[i]) {
	 	result.push_back(i);
	 	//cout << "pushed " << i << endl;
	}

	cout << "A shortest path from vertex " << traversed[0] << " to vertex " << id << ": " << traversed[0];
	for (auto rit = result.rbegin(); rit != result.rend(); ++rit) {
		cout << "->" << *rit;
	}	
	cout << endl;

	return;
}




