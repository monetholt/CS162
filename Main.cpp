/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include <iostream>
#include "validate.hpp"
#include <string>

using std::cout;
using std::endl;

int main() {
	
	
	int turns = 10;
	int counter = 0;
	int rowMax = 0;
	int columnMax = 0;
	//This has to be a triple pointer, because the final critter pointer has to point 
	// to an ant or a doodlebug

	rowMax = validateInt(0, 100000, "Enter the number of rows.");
	columnMax = validateInt(0, 100000, "Enter the number of columns.");

	Critter ***critArray = new Critter **[rowMax];
	for (int i = 0; i < rowMax; i++)
	{
		critArray[i] = new Critter*[columnMax];
	}
	//set up the array full of nullptrs
	for (int i = 0; i < rowMax; i++)
	{
		for (int x = 0; x < columnMax; x++)
		{
			critArray[i][x] = nullptr;
		}
	}
	
	critArray[5][5] = new Ant;

	while (counter < turns)
	{
		//reset if its moved at the beginning of each turn
		for (int i = 0; i < rowMax; i++)
		{
			for (int x = 0; x < columnMax; x++)
			{
				if (critArray[i][x] != nullptr)
				{
					critArray[i][x]->resetMoved();
				}
			}
		}


		for (int i = 0; i < rowMax; i++)
		{
			for (int x = 0; x < columnMax; x++)
			{
				//MAKE SURE THAT THERE IS A BUG THERE FIRST
				if (critArray[i][x] != nullptr)
				{
					if (critArray[i][x]->hasMoved() == false)
					{
						critArray[i][x]->move(critArray,i,x,rowMax,columnMax);
					}
				}
			}
		}
		for (int i = 0; i < rowMax; i++)
		{
			for (int x = 0; x < columnMax; x++)
			{
				if (critArray[i][x] != nullptr)
				{
					critArray[i][x]->breed(critArray, i, x, rowMax, columnMax);
				}
			}
		}
		
		
		std::cout << std::string(columnMax * 2 + 1,'-') << std::endl;
		for (int i = 0; i < rowMax; i++)
		{
			std::cout << "|";
			for (int x = 0; x < columnMax; x++)
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
		std::cout << std::string(columnMax * 2 + 1, '-') << std::endl;
			std::cin.ignore();

	}

	return 0;
}
