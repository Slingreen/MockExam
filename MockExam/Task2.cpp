/**********************************************************************************************************
 *  @file    Task2.CPP
 *  @author  Benjamin A.E. Darici 
 */
#include "Task2.h"	//	Task2(), outputList(), listSorter(), Dunno
#include <iostream>	//	cout, endl
#include <cstdlib>	//	srand(), rand()
#include <ctime>	//	time()
#include <vector>	//	vector, empty(), pop_back(), size()
#include <algorithm>//	sort()

//	A "main" function for Task 2
void Task2()
{
	system("CLS");
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::vector<Dunno*> list;
	char letter = 'A';
	for (int i = 0; i < 10; i++)
	{
		list.push_back(new Dunno);
		list[i]->name = letter;
		list[i]->no = i;
		list[i]->value = std::rand() % 20 + 1;
		letter++;
	}
	outputList(list);

	std::sort(list.begin(), list.end(), &listSorter);
	
	outputList(list);

	while (!list.empty()) {
		delete list[list.size() - 1];
		list.pop_back();
	}
}


//	Writes all the values to the terminal
void outputList(std::vector<Dunno*>& list) {
	std::cout << "No\tName\tValue\tHealth Bar" << std::endl
		<< "---------------------------------------------" << std::endl;
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i]->no << "\t" << list[i]->name << "\t" << list[i]->value << "\t";
		for (int j = 0; j < list[i]->value; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//	Help function to make std::sort() work
bool listSorter(const Dunno* a, const Dunno* b) {
		return a->value > b->value;
}