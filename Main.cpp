/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include "validate.hpp"
#include <string>
#include <time.h>


using std::cout;
using std::endl;

int main() {
	

	int turns = 0;
	int counter = 0;
	int rowMax = 0;
	int columnMax = 0;
	//This has to be a triple pointer, because the final critter pointer has to point 
	// to an ant or a doodlebug

	std::cout << "Extra credit options have been added!" << std::endl;

	rowMax = validateInt(0, 100000, "Enter the number of rows.");
	columnMax = validateInt(0, 100000, "Enter the number of columns.");
	
	turns = validateInt(0,100000, "Enter the number of turns: ");
	
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
	
	// random placement of critters
	// make sure the amount of bugs isnt more than possible spaces
	int startBugs = validateInt(1, rowMax * columnMax - 1, "Enter # of doodlebugs: ");
	int startAnts = validateInt(1, rowMax * columnMax - startBugs, "Enter # of ants: ");

	srand(time(NULL));
	
	bool placed = false; //used in a while loop to ensure a bug is placed and not overwritten
	for (int d = 1; d <= startBugs; d++)
	{
		//new bug so make sure that flag is reset
		placed = false;
		while (!placed)
		{
			int randX = rand() % columnMax;
			int randY = rand() % rowMax;
			//cout << randX << " " << randY << endl;

			if (critArray[randX][randY] == nullptr)
			{
				critArray[randX][randY] = new Doodlebug;
				//if bug placed, change flag.
				placed = true;
			}
		}

	}
	// same logic as previous for loop
	for (int e = 1; e <= startAnts; e++)
	{
		placed = false;
		while (!placed)
		{
			int randX = rand() % columnMax;
			int randY = rand() % rowMax;
			//cout << randX << " " << randY << endl;
			if (critArray[randX][randY] == nullptr)
			{
				critArray[randX][randY] = new Ant;
				placed = true;

			}
		}
	}


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

		//move all doodlebugs first
		for (int i = 0; i < rowMax; i++)
		{
			for (int x = 0; x < columnMax; x++)
			{
				//MAKE SURE THAT THERE IS A BUG THERE FIRST
				if (critArray[i][x] != nullptr && critArray[i][x]->getCritterChar() == 'X')
				{
					if (critArray[i][x]->hasMoved() == false)
					{
						critArray[i][x]->move(critArray, i, x, rowMax, columnMax);
					}
				}
			}
		}

		//next move all ants
		for (int i = 0; i < rowMax; i++)
		{
			for (int x = 0; x < columnMax; x++)
			{
				//MAKE SURE THAT THERE IS A BUG THERE FIRST
				if (critArray[i][x] != nullptr && critArray[i][x]->getCritterChar() == 'O')
				{
					if (critArray[i][x]->hasMoved() == false)
					{
						critArray[i][x]->move(critArray,i,x,rowMax,columnMax);
					}
				}
			}
		}

		//attempt to breed all critters.
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
		
		
		//print the board.
		std::cout << "Round #" << counter + 1 << std::endl;

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
		std::cout << "Press enter to continue." << std::endl;
			std::cin.ignore();

		counter++;
	}


	//deallocate memory for the critter array
	for (int i = 0; i < rowMax; i++)
	{
		for (int x = 0; x < columnMax; x++)
		{
			delete critArray[i][x];
		}

		delete[] critArray[i];
	}

	delete[] critArray;


	return 0;
}
