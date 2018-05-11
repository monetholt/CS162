/*******************************************************************************************************
* Program Name: Critter.hpp
* Date: 05/7/2018
* Description: The declaration of the Critter class.
*******************************************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
protected:
	int stepNumber;
	char critterChar;
	bool moved;

public:
	//constructor with no parameters.
	//Critter();

	//constructor with parameters to set starting step number and critter character
	//Critter(char c, int step);

	//getters
	virtual int getStepNumber();
	virtual char getCritterChar();

	/********************************************/
	virtual bool hasMoved();
	virtual void resetMoved();

	//increase stepNumber by 1
	virtual void addAStep();

	// set equal to zero, defining in doodle and ant class
	/*****************************************************/
	virtual void move(Critter***&, int, int)= 0;
	virtual void breed(Critter***&,int, int)= 0;
};

#endif