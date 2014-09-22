// Jonathan Petersen
// A01236750
// CS 1410 - Object Oriented Hello World
// Hello class implementation

#include "Hello.hpp"
#include <iostream>
#include <string>


//Default Constructor
Hello::Hello()
	: message("world!"),
	  name("Unknown name"),
	  major("Unknown major"),
	  hometown("Unknown hometown") {

	//Kind of ruins what we were going for with the member list . . . 
	cout << "Hello " << message << endl;

}

//Parameterized Constructor
Hello::Hello(string text)
	: message(text),
	  name("Unknown name"),
	  major("Unknown major"),
	  hometown("Unknown hometown") {

	//Kind of ruins what we were going for with the member list . . . 
	cout << "Hello " << message << endl;

}

//Destructor
Hello::~Hello() { cout << "Goodbye cruel " << message << endl; }

//Accessors
string Hello::getName() 	{ return name; }
string Hello::getMajor() 	{ return major; }
string Hello::getHometown() { return hometown; }

//Mutators
void Hello::setName(const string name) 			{ this -> name = name; return; }
void Hello::setMajor(const string major) 		{ this -> major = major; return; }
void Hello::setHometown(const string hometown)	{ this -> hometown = hometown; return; }
