/**********************************************************
File Name: Ant.hpp
Authors: Group
Date: 5/1//2018
Description: Header file for the Ant class.
**********************************************************/
#ifndef ANT_HPP
#define ANT_HPP

//NEED TO CHANGE THIS FOR FINAL UPLOAD
#include "Critter.hpp"

class Ant : public Critter
{
public:
	Ant();
	void move(Critter***&, int, int, int, int);
	void breed(Critter***&, int, int, int, int);
};

#endif
