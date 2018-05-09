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
	int stepNumber;
	char critterChar;

public:
	//constructor with no parameters.
	Critter();

	//constructor with parameters to set starting step number and critter character
	Critter(char c, int step);

	//getters
	int getStepNumber();
	char getCritterChar();

	//increase stepNumber by 1
	void addAStep();

	virtual int move();
	virtual bool breed();
};

#endif