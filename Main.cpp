/*******************************************************************************************************
* Program Name: Main.cpp
*******************************************************************************************************/
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include "validate.hpp"
#include <string>

using std::cout;
using std::endl;

int main() {
	

	int turns = 0;
	int counter = 0;
	int rowMax = 0;
	int columnMax = 0;
	//This has to be a triple pointer, because the final critter pointer has to point 
	// to an ant or a doodlebug

	rowMax = validateInt(0, 100000, "Enter the number of rows.");
	columnMax = validateInt(0, 100000, "Enter the number of columns.");
	
	turns = stepNum();
	
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
	int startBugs = 2;
	int startAnts = 2;

	srand(std::time(NULL));
	
	for (int d = 1; d <= startBugs; d++)
	{
		int randX = rand() % columnMax;
		int randY = rand() % rowMax;
		cout << randX << " " << randY << endl;
		critArray[randX][randY] = new Doodlebug;
	}
	
	for (int e = 1; e <= startAnts; e++)
	{
		int randX = rand() % columnMax;
		int randY = rand() % rowMax;
		cout << randX << " " << randY << endl;
		critArray[randX][randY] = new Ant;
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
