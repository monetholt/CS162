/*******************************************************************************************************
* Program Name: Doodlebug.cpp
* Date: 05/7/2018
* Description: The definition of the Doodlebug class
*******************************************************************************************************/
#include "Doodlebug.hpp"
#include <cstdlib>
#include <ctime>

//constructor to initialize data.
Doodlebug::Doodlebug()
{
	stepNumber = stepLastMeal = 0;
	critterChar = 'X';
	moved = false;

	//seed the random number generator.
	srand(time(NULL));
}

/*******************************************************************************************************
* Description: Moves the doodlebug
*******************************************************************************************************/
void Doodlebug::move(Critter***& array, int row, int column, int rowMax, int colMax)
{
	stepNumber++;

	//should already be false at this point.
	moved = false;

	int ant2EatX = -1;
	int ant2EatY = -1;

	//look at each adjacent cell until we find an ant to eat. If we find one, save the coordinates.
	if (row - 1 >= 0 && array[row - 1][column] != nullptr && array[row - 1][column]->getCritterChar() == 'O')
	{
		ant2EatX = row - 1;
		ant2EatY = column;
	}
	else if (column + 1 < colMax && array[row][column + 1] != nullptr && array[row][column + 1]->getCritterChar() == 'O')
	{
		ant2EatX = row;
		ant2EatY = column + 1;
	}
	else if (row + 1 < rowMax && array[row + 1][column] != nullptr  && array[row + 1][column]->getCritterChar() == 'O') {
		ant2EatX = row + 1;
		ant2EatY = column;
	}
	else if (column - 1 >= 0 && array[row][column - 1] != nullptr  && array[row][column - 1]->getCritterChar() == 'O') {
		ant2EatX = row;
		ant2EatY = column - 1;
	}

	//if we have valid coordinates for an ant to eat.
	if (ant2EatX >= 0 && ant2EatX < rowMax && ant2EatY >= 0 && ant2EatY < colMax) {
		//remove this ant
		delete array[ant2EatX][ant2EatY];
		//move to this position
		array[ant2EatX][ant2EatY] = array[row][column];
		//empty the current spot
		array[row][column] = nullptr;
		//set last meal to this step
		stepLastMeal = stepNumber;

		moved = true; //set moved to true
	}

	//if we still didn't find an ant to eat and move, try to randomly pick a direction and move there if it is free
	if(!moved) {

		//choose a random direction 0-4.
		int direction = rand() % 4;

		//0 = up, 1 = right, 2 = down, 3 = left
		if (direction == 0)
		{
			if (row - 1 >= 0 && array[row - 1][column] == nullptr)
			{
				array[row - 1][column] = array[row][column];
				array[row][column] = nullptr;
			}
		}
		else if (direction == 1)
		{
			if (column + 1 < colMax && array[row][column + 1] == nullptr)
			{
				array[row][column + 1] = array[row][column];
				array[row][column] = nullptr;
			}
		}
		else if (direction == 2)
		{
			if (row + 1 < rowMax && array[row + 1][column] == nullptr)
			{
				array[row + 1][column] = array[row][column];
				array[row][column] = nullptr;
			}
		}
		else if (direction == 3) {
			if (column - 1 >= 0 && array[row][column - 1] == nullptr)
			{
				array[row][column - 1] = array[row][column];
				array[row][column] = nullptr;
			}
		}
		moved = true;
	}

}

void Doodlebug::breed(Critter***& array, int row, int column, int rowMax, int colMax)
{
	//first check to see if this doodlebug is going to starve.

	if (stepNumber - stepLastMeal >= 3) {
		delete array[row][column];
		array[row][column] = nullptr;
	}
	else {
		int breedDirection = 0;
		//flags for checking a direction
		bool up, right, down, left;
		bool babyBorn = false;
		up = right = down = left = true;

		//checks to see if the doodlebug can breed
		if (stepNumber % 8 == 0 && stepNumber > 0)
		{
			//keep trying to breed until we have checked every direction and no empty spots or a baby is born.
			while ((up || right || left || down) && !babyBorn)
			{
				breedDirection = rand() % 4;

				int x = row;
				int y = column;

				if (breedDirection == 0)
				{
					up = false;
					x--;
				}
				else if (breedDirection == 1)
				{
					right = false;
					y++;
				}
				else if (breedDirection == 2)
				{
					down = false;
					x++;
				}
				else
				{
					left = false;
					y--;
				}

				if (x >= 0 && x < rowMax && y >= 0 && y < colMax && array[x][y] == nullptr)
				{
					array[x][y] = new Doodlebug;
					babyBorn = true;
				}
			}
		}
	}

}

