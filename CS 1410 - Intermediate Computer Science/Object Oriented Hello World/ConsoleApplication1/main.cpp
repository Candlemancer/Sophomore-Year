// Jonathan Petersen
// A01236750
// CS 1410 - Object Oriented Hello World
// Main
// Stretch goal: Clean, elegant code

#include <iostream>
#include "hello.hpp"

using namespace std;


int main() {

	//Create a Hello object
	Hello myHello("world!");

	//Tell the object my information
	myHello.setName("Jonathan Petersen");
	myHello.setMajor("Computer Science and Management Information Systems");
	myHello.setHometown("Salt Lake City, UT");

	//Get the information from the object
	cout << "My name is " << myHello.getName() << endl;
	cout << "My major is " << myHello.getMajor() << endl;
	cout << "I am from " << myHello.getHometown() << endl;

	return 0;
}
