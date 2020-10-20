/**********************************************************************************************************
 *      A mock exam
 *
 *      A program that answers several different tasks on a mock exam
 *
 *  @file    MockExam.CPP
 *  @author  Benjamin A.E. Darici
 */


#include <iostream>     //  cout
#include "Function.h"   //  writeMenu(), Read_Command()
#include "login.h"      //  login()
#include "Task1.h"      //  Task1()
#include "Task2.h"      //  Task2()
#include "Task3.h"      //  Task3()
#include "Task4.h"      //  Task4()

//  The main function of the program, essentially a menu
int main()
{
    char command{ ' ' };
	if (login())
	{
		writeMenu();

        command = Read_Command("Command");

        while (command != '5')
        {
            std::cin.ignore(32767, '\n');
            switch (command)
            {
            case '1': Task1(); break;
            case '2': Task2(); break;
            case '3': Task3(); break;
            case '4': Task4(); break;
            default: 
                std::cout << "Wrong input ... Do you want to try again: ";
                command = Read_Command("(y / n)");
                if (command == 'N')
                {
                    return 0;
                }
                break;
            }
            writeMenu();
            command = Read_Command("Command");
        }
	}
}
/*  _____     ____
   /      \  |  o |
  |        |/ ___\|
  |_________/
  |_|_| |_|_|
  Slow and Steady,
  makes the race!
*/