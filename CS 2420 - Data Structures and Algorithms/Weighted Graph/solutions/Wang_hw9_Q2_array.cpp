#include <iostream>
#include <fstream>
using namespace std;

//enum colorType {white, blue, red};

const int MAX = 10000;

struct Vertex
{
	int id;//the id of the vertex
	int weight; //the weight of an edge (u,v), where v is the current node and v is in the adj list of vertex u
	Vertex * next;
	Vertex(int id_input, int weight_input = 1, Vertex * next_input = NULL)
	{
		id = id_input;
		weight = weight_input;
		next = next_input;
	}
};

class Graph
{
	private:
		int * pre;//the predecessors
		int * dis;//the shortest path distances

	public:
		int n;//the number of vertices, the ids of the vertices are from 0 to n-1  
		Vertex ** adj;//adj[i] points the head of the adjacency list of vertex i
		
		Graph(int n_input);//the class constructor

		void Dijkstra(int s);//compute a shortest path tree from the source vertex s in a general graph

		void printSP(int source, int v);//print the shortest path from the source vertex to v
		int getSPdis(int v);//return the shortest path distance from the source vertex to v

		void setAdjLists(int * adjM);// convert the adj matrix M to adj list
		void printAdjLists();//print the adj list of the graph
};

//implemented by an array
void Graph::Dijkstra(int s = 0)
{
	for(int i = 0; i < n; i++)
	{
		dis[i] = MAX;        // set it to a very large number
		pre[i] = -1;          // we use -1 to represent NULL because there is no vertex whose id is -1 
	}

	dis[s] = 0; //the distance of the source is 0

	//implement the priority queue by an array
	int * Q = new int [n];
	for(int i = 0; i < n; i++)
		Q[i] = 1;// 1 means vertex i is in the queue
	// we check whehter Q is empty by a count, which is initially set to n
	int count = n;

	while(count > 0)//Q is not empty
	{
		//the following performs the Extract-Min operation on Q
		int min_sofar;
		int min = MAX;
        for(int i = 0; i < n; i++)
		{
			if(Q[i] == 1 && dis[i] < min)
			{
				min_sofar = i;
				min = dis[i];
			}
		}
		int u = min_sofar;
		//remove u from Q
		Q[u] = 0;
		count --;

		Vertex * v = adj[u];
		while(v != NULL)
		{
			if(dis[v->id] > dis[u] + v->weight)//v->weight is the weight w(u,v)
			{
				dis[v->id] = dis[u] + v->weight;
				pre[v->id] = u; 
			}
			v = v->next;
		}
	}
}

//return
int Graph::getSPdis(int v)
{
	return dis[v];
}

void Graph::printSP(int source, int v)
{
	if(v == source)
		cout << source;
	else
	{
		printSP(source, pre[v]);
		cout << "->" << v; 
	}
}


Graph::Graph(int n_input)
{
	n = n_input;
	adj = new Vertex * [n];
	//initialize adj[i] to NULL
	for(int i = 0; i < n; i++)
		adj[i] = NULL;
	
	pre = new int [n];
	dis = new int [n];
}

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
			if(adjM[i * n + j] > 0)
			{
				//create a new node and add it to the front of adj[i]
				Vertex * v = new Vertex (j, adjM[i * n + j]);
				v->next = adj[i];
				adj[i] = v;
			}
		}
	}
}

void Graph::printAdjLists()
{
	cout << "The following are the adjacent lists with edge weights in the parentheses:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "Adj list of vertex " << i << ": "; 
		Vertex *v = adj[i];
		while(v != NULL)
		{
			if (v->next != NULL)
				cout << v->id << "(" << v->weight << ")" << "->";
			else
				cout << v->id << "(" << v->weight << ")";
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
	inputFile.open("hw9_Q2_input.txt");
	if (!inputFile)
		cout << "Error opening the input file " << endl;
	
	int n;
	//read the number in the first line, which is the number of vertices of
	//the input graph
	inputFile >> n;

	cout << "The number of vertices is: " << n << endl << endl;

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

	int source_vertex = 0;

	graph.Dijkstra(source_vertex);

	//after the Dijkstra's algorithm, the following for loop is supposed to
	//print the shortest paths from the source vertex to all other
	//vertices
	for(int i = 1; i <= n-1; i++)
	{
		cout << "The shortest path from the source vertex " << source_vertex << " to vertex " << i <<": ";
		graph.printSP(source_vertex, i);// print the shortest path from 0 to 5 with source 0
		cout << endl;
	}

	cout << endl;

	//the following for loop is supposed to
	//print the shortest path distances from the source vertex to all other
	//vertices
	for(int i = 1; i <= n-1; i++)
	{
		cout << "The shortest path distance from the source vertex " << source_vertex << " to vertex " << i <<" is: ";
	    cout << graph.getSPdis(i) << endl;
	}

	return 0;
}
