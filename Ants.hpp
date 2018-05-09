/*******************************************************************************************************
* Program Name: Ants.hpp
* Date: 05/7/2018
* Description: The declaration of the Ants class which is derived from 
* the Critter class
*******************************************************************************************************/
#include "Critter.hpp"

#ifndef ANTS_HPP
#define ANTS_HPP

class Ants : public Critter
{
public:
  //Ants();   need to expand with parameters
  int move();
  bool breed();

};
#endif
