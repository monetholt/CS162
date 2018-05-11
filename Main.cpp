/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	//Critter critter = Critter('X' , 3);
	
	int turns = 10;
	int counter = 0;
	//This has to be a triple pointer, because the final critter pointer has to point 
	// to an ant or a doodlebug
	Critter ***critArray = new Critter **[20];
	for (int i = 0; i < 20; i++)
	{
		critArray[i] = new Critter*[20];
	}
	//set up the array full of nullptrs
	for (int i = 0; i < 20; i++)
	{
		for (int x = 0; x < 20; x++)
		{
			critArray[i][x] = nullptr;
		}
	}
	critArray[5][5] = new Ant;

	while (counter < turns)
	{
		//reset if its moved at the beginning of each turn
		for (int i = 0; i < 20; i++)
		{
			for (int x = 0; x < 20; x++)
			{
				if (critArray[i][x] != nullptr)
				{
					critArray[i][x]->resetMoved();
				}
			}
		}


		for (int i = 0; i < 20; i++)
		{
			for (int x = 0; x < 20; x++)
			{
				//MAKE SURE THAT THERE IS A BUG THERE FIRST
				if (critArray[i][x] != nullptr)
				{
					if (critArray[i][x]->hasMoved() == false)
					{
						critArray[i][x]->move(critArray,i,x);
					}
				}
			}
		}
		for (int i = 0; i < 20; i++)
		{
			for (int x = 0; x < 20; x++)
			{
				if (critArray[i][x] != nullptr)
				{
					critArray[i][x]->breed(critArray, i, x);
				}
			}
		}
		
		
		std::cout << "-----------------------------------------" << std::endl;
		for (int i = 0; i < 20; i++)
		{
			std::cout << "|";
			for (int x = 0; x < 20; x++)
			{
				if (critArray[i][x] == nullptr)
				{
					std::cout << ' ';
				}
				else
				{
					std::cout << critArray[i][x]->getCritterChar();
				}
				std::cout << "|";
				
			}
			std::cout << std::endl;
		}
			std::cin.ignore();

	}

	//cout << critter.getStepNumber() << endl;
	//cout << critter.getCritterChar() << endl;

	return 0;
}
