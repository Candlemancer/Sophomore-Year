// Jonathan Petersen
// A01236750
// String Parsing 
// String Parser Implementation

#include "StringParser.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
StringParser::StringParser() 
	: str("Default Constructor") {}

//Paramater Constructor
StringParser::StringParser(string input) 
	: str(input) {}


void StringParser::print() {

	string currentChunk;
	string paramaterOne;
	string paramaterTwo;
	int idLength = 2;
	int columnWidth = 13;

	delim = str[1];
	if (str[str.length() - 1] != delim) str += delim;

	if (str[0] == 'Y' || str[0] == 'y') {

		//Remove identifier
		str = str.substr(idLength, str.length() -idLength);

		//Get The first chunk before the delim
		currentChunk = str.substr(0, str.find(delim));

		cout << left << setw(columnWidth) << "Delimiter: " << delim << endl;

		while (str.find(delim) != string::npos) {
			
			switch (currentChunk[0]) {

				case 'I':
				case 'i':
					cout << setw(columnWidth) << "Integer: " << stoi(currentChunk.substr(idLength, 
							currentChunk.length() - idLength)) << endl;
					break;

				case 'F':
				case 'f':
					cout << setw(columnWidth) << "Float: " << stof(currentChunk.substr(idLength, 
							currentChunk.length() - idLength)) << endl;
					break;

				case 'D':
				case 'd':
					cout << setw(columnWidth) << "Double: " << stod(currentChunk.substr(idLength, 
							currentChunk.length() - idLength)) << endl;
					break;

				case 'S':
				case 's':
					cout << setw(columnWidth) << "String: " << currentChunk.substr(idLength, 
							currentChunk.length() - idLength) << endl;
					break;

				default:
					cout << "Unable to determine type. Continuing . . . " << endl;

			}

			str = str.substr(currentChunk.length() + 1, str.length() - currentChunk.length());
			currentChunk = str.substr(0, str.find(delim));
			
		}

	}

	if (str[0] == 'I' || str[0] == 'i') {

		//Remove identifier
		str = str.substr(idLength, str.length() -idLength);

		//Get The first chunk before the delim
		currentChunk = str.substr(0, str.find(delim));
		str = str.substr(currentChunk.length() + 1, str.length() - currentChunk.length());


		while (str.find(delim) != string::npos && str.length() != 1) {

			switch (str[0]) {

				case 'F':
				case 'f':
					paramaterOne = str.substr(idLength, str.find(delim, idLength) 
							- idLength);
					currentChunk = paramaterOne + " found at position " 
							+ to_string(currentChunk.find(paramaterOne));
					str = str.substr(idLength + paramaterOne.length() + 1, str.length() - idLength 
							+ paramaterOne.length() - 1);
					break;

				case 'R':
				case 'r':
					paramaterOne = str.substr(idLength, str.find(delim, idLength) 
							- idLength);
					paramaterTwo = str.substr(idLength + paramaterOne.length() + 1, str.find(delim, 
							idLength + paramaterOne.length() + 1) - (idLength 
							+ paramaterOne.length() + 1));
					currentChunk = currentChunk.substr(0, currentChunk.find(paramaterOne))
							+ paramaterTwo + currentChunk.substr(currentChunk.find(paramaterOne)
							+ paramaterOne.length(), currentChunk.length() - 1);
					str = str.substr(idLength + paramaterOne.length() + 1 + paramaterTwo.length() 
							+ 1, str.length() + idLength + paramaterOne.length() - 1
							+ paramaterTwo.length());
					break;

				case 'C':
				case 'c':
					paramaterOne = str.substr(idLength, str.find(delim, idLength) 
							- idLength);
					currentChunk = currentChunk + paramaterOne;
					str = str.substr(idLength + paramaterOne.length() + 1, str.length() - idLength 
							+ paramaterOne.length() - 1);
					break;

				case 'S':
				case 's':
					paramaterOne = str.substr(idLength, str.find(delim, idLength) 
							- idLength);
					paramaterTwo = str.substr(idLength + paramaterOne.length() + 1, str.find(delim, 
							idLength + paramaterOne.length() + 1) - (idLength 
							+ paramaterOne.length() + 1));
					currentChunk = currentChunk.substr(stoi(paramaterOne), stoi(paramaterTwo));
					str = str.substr(idLength + paramaterOne.length() + 1 + paramaterTwo.length() 
							+ 1, str.length() + idLength + paramaterOne.length() - 1
							+ paramaterTwo.length());
					break;

				default:
					cout << "Unable to determine operation. Continuing." << endl;
			}

		}

		cout << currentChunk << endl;

	}

}
