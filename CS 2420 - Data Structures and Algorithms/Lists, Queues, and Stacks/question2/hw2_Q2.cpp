#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int ARRAY_SIZE = 100;

void input(int A[], int & n, const string & fileName) 
{
	ifstream inputFile;
	int value;

	inputFile.open(fileName.c_str());
	
	if (!inputFile)
	{
		cout << "Error opening the file " << fileName << endl;
		exit(0);
	}


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
	
	if (!outputFile)
	{
		cout << "Error opening the file " << fileName << endl;
		exit(0);
	}

	for (int i = 0; i < n; i++)
	  	 outputFile << A[i] << "  "; 
	 
	outputFile.close();
}

struct ListNode
{
	int value;
	ListNode *next;
	ListNode (int input_value, ListNode * input_next = NULL)
	{ value = input_value; next = input_next;}
};

class Queue
{
	private:
		ListNode *front;
		ListNode *rear;

	public:
		Queue() { front = NULL; rear = NULL; }
		~Queue();
		void enqueue(int x);// put the new number at the end of the queue
		int dequeue();//return the first number in the queue and remove it from the queue
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750

//please complete the following function
void Queue::enqueue(int x) {

	if (front == NULL) {
		front = rear = new ListNode(x, NULL);
		return;
	}

	rear->next = new ListNode(x, NULL);
	rear = rear->next;

	return;
}

//please complete the following function
int Queue::dequeue() {

	if(front == NULL) {
		cout << "Nothing left to dequeue. Exiting with error -1.";
		exit(-1);
	}

	int temp = front->value;
	ListNode* destroy = front;
	front = front->next;
	delete destroy;
	return temp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Queue::~Queue()
{
	while(front != NULL)
	{
		ListNode *garbageNode = front;
		front = front->next;
		delete garbageNode;
	}

}

int main()
{
	int A[ARRAY_SIZE];// store numbers for doing enqueue operations 
	int n = 0;
	string inputFile1 = "hw2_Q2_input.txt"; // file with input data for enqueue

	input(A, n, inputFile1); 

	Queue queue;

	cout << "Enqueuing..." << endl;
	for (int i = 0; i < n; i++)
		queue.enqueue(A[i]);

	cout << endl << "Duqeuing..." << endl;
	int B[10]; // temporarily store the results of ten dequeue operations
	for (int i = 0; i < 10; i++)
		B[i] = queue.dequeue();

	//print the array B to the output file
	string outputFile = "hw2_Q2_output.txt"; // the output file 
	output(B, 10, outputFile);

	return 0;
}
