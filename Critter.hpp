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
	
	//getters
	virtual char getCritterChar();

	/********************************************/
	virtual bool hasMoved();
	virtual void resetMoved();


	// set equal to zero, defining in doodle and ant class
	virtual void move(Critter***&, int, int, int, int)= 0;
	virtual void breed(Critter***&,int, int, int, int)= 0;
};

#endif