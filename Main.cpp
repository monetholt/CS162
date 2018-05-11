/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Critter critter = Critter('X' , 3);
	
	Critter **critArray = new Critter *[10];
	critArra
	cout << critter.getStepNumber() << endl;
	cout << critter.getCritterChar() << endl;

	return 0;
}
