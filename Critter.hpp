/*******************************************************************************************************
* Program Name: Critter.hpp
* Date: 05/7/2018
* Description: The declaration of the Critter class.
*******************************************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
private:
	int steps;
	int xCoord;
	int yCoord;

public:
	//constructor with no parameters.
	Critter();

	//constructor with parameters to set x, y coordinate
	Critter(int x, int y);

	//getters
	int getSteps();

	//setters
	void setSteps(int);

	virtual void move();
};

#endif