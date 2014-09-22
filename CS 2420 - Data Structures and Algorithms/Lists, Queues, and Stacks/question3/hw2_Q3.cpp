#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Stack
{
	private:
		int *stackArray;
		int capacity;// the size of the array stackArray
		int top;

	public:
		Stack(int capacity_input);
		~Stack() {delete [] stackArray;}
		void push (int x);//push a new value x
		int pop (); 
		bool isEmpty() const;//check whether the stack is empty
		bool isFull() const;//check whether the stack is full
};

Stack::Stack(int capacity_input)
{
	// set the capacity
	capacity = capacity_input;
	// dynamically create an array of size equal to ''capacity''
	stackArray = new int[capacity];
	top = 0;
}

bool Stack::isEmpty() const
{
	if (top == 0)
		return true;
	else
		return false;
}

bool Stack::isFull() const
{
	if (top == capacity)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Petersen
// A01236750
 
//please complete the following function
int Stack::pop() {

	if (top == 0) {
		cout << "Nothing left to pop. Exiting with error -1";
		exit(-1);
	}

	top--;
	return stackArray[top];

}

//please complete the following function
void Stack::push(int x) {

	if (top == capacity) {
		cout << "No room left in the inn. Exiting with error -2";
		exit(-2);
	}

	stackArray[top] = x;
	top++;

	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const int STACK_SIZE = 30;  

int main()
{
	Stack stack(STACK_SIZE); 
	string inputFileName = "hw2_Q3_input.txt"; // input file with operations 
	string outputFileName = "hw2_Q3_output.txt"; // output file

	//open files
	ifstream inputFile;
	inputFile.open(inputFileName.c_str());
	if (!inputFile)
	{
		cout << "Error opening the file " << inputFileName << endl;
		exit(0);
	}
	
	ofstream outputFile;
	outputFile.open(outputFileName.c_str());
	
	if (!outputFile)
	{
		cout << "Error opening the file " << outputFileName << endl;
		exit(0);
	}


	//read operations from the input file
	string op;
	int value;
	while(inputFile >> op)
	{
		if (op == "pop") // a pop operation, 
			outputFile << stack.pop() << endl;// the pop result is print in the output file
		else // a push operation
		{
			inputFile >> value;
			stack.push(value);
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
