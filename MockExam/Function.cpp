/**********************************************************************************************************
 *  @file    Function.CPP
 *  @author  Benjamin A.E. Darici 
 */
#include "Function.h"   //  writeMenu(), Read_Command()
#include <iostream>     //  cout, toupper()

// A tiny function to write out the choices the switch provides in the main function
void writeMenu()
{
    std::cout << "The following commands are available: \n"
        << "\t 1    Runs task 1\n"
        << "\t 2    Runs task 2\n"
        << "\t 3    Runs task 3\n"
        << "\t 4    Runs task 4\n"
        << "\t 5    Quits program\n";
}

// A tiny function just to read input commands
char Read_Command(const char* c)
{
    char command;
    std::cout << c << ":  ";
    std::cin >> command;
    return(toupper(command));
}


