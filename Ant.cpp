#include "Ant.hpp"
#include <random>


Ant::Ant()
{
	stepNumber = 0;
	critterChar = 'O';
	moved = false;
}

void Ant::move(Critter***& array, int row, int column, int rowMax, int colMax)
{
	int direction = rand() % 4;
	//0 = up, 1 = right, 2 = down, 3 = left
	if (direction == 0)
	{
		if (row - 1 >= 0 && array[row-1][column] == nullptr)
		{
			array[row - 1][column] = array[row][column];
			array[row][column] = nullptr;
		}
	}
	else if (direction == 1)
	{
		if (column + 1 < colMax && array[row][column+1] == nullptr)
		{
			array[row][column + 1] = array[row][column];
			array[row][column] = nullptr;
		}
	}
	else if (direction == 2)
	{
		if (row + 1 < rowMax && array[row+1][column] == nullptr)
		{
			array[row + 1][column] = array[row][column];
			array[row][column] = nullptr;
		}
	}
	else if (direction == 3)
		if (column - 1 >= 0 && array[row][column - 1] == nullptr)
		{
			array[row][column - 1] = array[row][column];
			array[row][column] = nullptr;
		}
	stepNumber++;
	moved = true;
}

void Ant::breed(Critter***& array, int row, int column, int rowMax, int colMax)
{
	int breedDirection = 0;
	//flags for checking a direction
	bool up, right, down, left;
	bool babyBorn = false;
	up = right = down = left = true;
	
		//checks to see if the ant can breed
		if (stepNumber % 3 == 0 && stepNumber > 0)
		{
			while ((up ||right || left|| down) && !babyBorn )
			{
				breedDirection = rand() % 4;
				if (breedDirection == 0)
				{
					up = false;
					if (row - 1 >= 0 && array[row - 1][column] == nullptr)
					{
						array[row - 1][column] = new Ant;
						babyBorn = true;
					}
				}
				else if (breedDirection == 1)
				{
					right = false;
					if (column + 1 < colMax && array[row][column + 1] == nullptr)
					{
						array[row][column + 1] = new Ant;
						babyBorn = true;
					}

				}
				else if (breedDirection == 2)
				{
					down = false;
					if (row + 1 < rowMax && array[row + 1][column] == nullptr)
					{
						array[row + 1][column] = new Ant;
						babyBorn = true;
					}
				}
				else if (breedDirection == 3)
				{
					left = false;
					if (column - 1 >= 0 && array[row][column - 1] == nullptr)
					{
						array[row][column - 1] = new Ant;
						babyBorn = true;
					}
				}
			}
		}
}

