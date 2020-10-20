/**********************************************************************************************************
 *  @file    Task1.CPP
 *  @author  Benjamin A.E. Darici
 */
#include "Task1.h"	//	Task1()
#include <iostream>	//	cout, endl
#include <cstdlib>	//	srand(), rand()
#include <ctime>	//	time()

 //	A "main" function for Task 1
void Task1()
{
	system("CLS");
	int diceThrow[6]{ 0,0,0,0,0,0 };	
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock

	for (int i = 0; i < 2000; i++)
	{
		switch (std::rand() % 6 +1)
		{
		case 1: diceThrow[0]++; break;
		case 2: diceThrow[1]++; break;
		case 3: diceThrow[2]++; break;
		case 4: diceThrow[3]++; break;
		case 5: diceThrow[4]++; break;
		case 6: diceThrow[5]++; break;
		default:
			std::cout << "\n\nError, something, dice rolled invalid number\n\n"; break;
		}
	}

	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 << " : " << diceThrow[i] << " times" << std::endl;
	}
	std::cout << std::endl;
}
