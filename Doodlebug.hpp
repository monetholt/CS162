/**********************************************************
File Name: Doodle.hpp
Authors: Group
Date: 5/1//2018
Description: Header file for the Doodlebug class.
**********************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
private: 
	int stepLastMeal;

public:
	Doodlebug();
	void move(Critter***&, int, int, int, int);
	void breed(Critter***&, int, int, int, int);
};

#endif
