#include <iostream>
#include "gtest\gtest.h"

using namespace std;

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
   
	RUN_ALL_TESTS();
  	
	std::cin.get();

	return 0;
}