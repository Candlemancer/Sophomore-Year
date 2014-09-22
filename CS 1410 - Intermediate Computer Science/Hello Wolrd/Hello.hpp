// Jonathan Petersen
// A01236750
// CS 1410 - Object Oriented Hello World
// Hello class header

#ifndef HELLO_HPP
#define HELLO_HPP

#include <string>

using namespace std;


class Hello {

	public:
		//Constructors
		Hello(string);
		~Hello();

		//Methods
		string getName();
		string getMajor();
		string getHometown();
		void setName(string);
		void setMajor(string);
		void setHometown(string);

	protected:
		//Variables
		string message;
		string name;
		string major;
		string hometown;

};

#endif
