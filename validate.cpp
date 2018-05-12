/******************************************************************
Program Name: validate.cpp
Date: 5/11/2018
Description: A function that will validate integer input, that
will hopefully be resused in future projects. Based on the
input validation from the cs 162 slack channel. Taken from
my lab4, used in group project
****************************************************************/


#include "validate.hpp"
#include <sstream>
#include <iostream>

int validateInt(int min, int max, std::string question)
{
	bool flag = false;
	std::string input;
	int correctInput;

	do
	{
		std::cout << question << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);

		if (sStream >> correctInput && !(sStream >> input))
		{
			if (correctInput > max || correctInput < min)
			{
				std::cout << "Input a number between " << min << " and " << max << "." <<
					std::endl;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			std::cout << "Enter an integer only." << std::endl;
		}

	} while (flag == false);

	return correctInput;
}

int stepNum()
{
	int steppers = 0;
	std::cout << "Enter number of steps to run" << std::endl;
	std::cin >> steppers;

	if (steppers <= 0)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Enter a positive number" << std::endl;
		stepNum();
	}
	else if (steppers > 0)
	{
		std::cout << "Game will run " << steppers << " times" << std::endl;
		std::cin.ignore(1, '\n');
		return steppers;
	}
}
