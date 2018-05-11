/*******************************************************************************************************
* Program Name: Critter.cpp
* Date: 05/7/2018
* Description: The definition of the Critter class
*******************************************************************************************************/

#include "Critter.hpp"

/*******************************************************************************************************
Description: get the critter character.
*******************************************************************************************************/
char Critter::getCritterChar()
{
	return critterChar;
}

/**************************************************
Returns if the critter has moved or not
***************************************************/
bool Critter::hasMoved()
{
	return moved;
}

/******************************************************
Resets if a critter has moved at the beginning of each 
turn
*******************************************************/
void Critter::resetMoved()
{
	moved = false;
}