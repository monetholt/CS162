/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Critter critter = Critter(0, 0);
	
	cout << critter.getSteps() << endl;

	return 0;
}
