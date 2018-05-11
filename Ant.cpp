#include "Ant.hpp"
#include <random>


Ant::Ant()
{
}

void Ant::move(Critter***& array, int row, int column)
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
		if (column + 1 <= 20 && array[row][column+1] == nullptr)
		{
			array[row][column + 1] = array[row][column];
			array[row][column] = nullptr;
		}
	}
	else if (direction == 2)
	{
		if (row + 1 <= 20 && array[row+1][column] == nullptr)
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
}

