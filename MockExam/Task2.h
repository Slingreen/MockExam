#pragma once
#include <vector>

struct Dunno
{
	int no, value;
	char name;
};

void Task2();
void outputList(std::vector<Dunno*>& list);
bool listSorter(const Dunno* a, const Dunno* b);