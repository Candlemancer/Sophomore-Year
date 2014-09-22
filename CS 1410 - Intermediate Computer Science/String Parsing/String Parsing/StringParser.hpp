// Jonathan Petersen
// A01236750
// String Parsing
// String Parser Definition

#ifndef _STRING_PARSE_H
#define _STRING_PARSE_H

#include <string>

using namespace std;

class StringParser{

public:
	//Constructors
	StringParser();
	StringParser(string);

	//Methods
	void print();

private:
	char delim;
	string str;

};

#endif