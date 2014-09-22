#include "RomanNumeral.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

RomanNumeral::RomanNumeral(string input) 
	: numeral(input),
	  value(-1)		{

	if (!validate()) { return; }
	compute();

}

bool RomanNumeral::validate() {

	regex validator("(M*(CM)?)(D?(CD)?)(C{0,3}(XC)?)(L?(XL)?)(X{0,3}(IX)?)(V?(IV)?)(I{0,3})");

	if (numeral == "") return false;
	if (regex_match(numeral, validator)) return true;

	return false;
}

void RomanNumeral::compute() {

	unordered_map<char, int> numeralMap;
	numeralMap.emplace('M', 1000);
	numeralMap.emplace('D',  500);
	numeralMap.emplace('C',  100);
	numeralMap.emplace('L',   50);
	numeralMap.emplace('X',   10);
	numeralMap.emplace('V',    5);
	numeralMap.emplace('I',    1);
	value = 0;

	//Add or subtract all but the last number.
	for (int i=0; i<numeral.length() - 1; i++) {
		
		if (numeralMap.at(numeral[i]) < numeralMap.at(numeral[i + 1])) {

			value -= numeralMap.at(numeral[i]);
			continue;
		}

		value += numeralMap.at(numeral[i]);		

	}

	//Add the final number
	value += numeralMap.at(numeral[numeral.length() - 1]);

	return;
}
