/**********************************************************************************************************
 *  @file    login.CPP
 *  @author  Benjamin A.E. Darici
 */
#include "login.h"  //  login(), drawGrid(), movement()
#include <iostream> //  toupper(), cout, endl
#include <conio.h>  //  _getch()
#include <string>   // string, to_string()

 //	A "main" function for the login page
bool login()
{
    int grid[3][3]{
        {1,2,3},
        {4,5,6},
        {7,8,9} },
        pos[2]{ 0,0 },
        attempt{ 0 };
    std::string pasword;

    do
    {
        pos[0] = pos[1] = 0;
        pasword = "";
        for (int i = 0; i < 4; i++)
        {
            drawGrid(pos, grid);
            movement(pos);
            system("CLS");
            pasword += std::to_string(grid[pos[0]][pos[1]]);
        }
        if (pasword == "4523") {
            return true;
        }
        attempt++;
    } while (attempt < 3);
    
    return false;
}

//  Draws the grid from where the input is taken
void drawGrid(int(&pos)[2], int(&grid)[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::endl << "---------------" << std::endl;
        for (int j = 0; j < 3; j++)
        {
            if (i == pos[0] && j == pos[1]) {
                std::cout << " | *";
            }
            else
            {
                std::cout << " | " << grid[i][j];
            }
        }
        std::cout << " | ";
    }
    std::cout << std::endl << "---------------" << std::endl;
}

//  Movement options for the login grid
void movement(int(&pos)[2])
{
    char c;
    bool move = false;
    while (!move)
    {
        c = _getch();
        if (toupper(c) == 'W')
        {
            if (pos[0] != 0) {
                pos[0] -= 1;
                move = true;
            }
        }
        else if (toupper(c) == 'A')
        {
            if (pos[1] != 0) {
                pos[1] -= 1;
                move = true;
            }
        }
        else if (toupper(c) == 'S')
        {
            if (pos[0] != 2) {
                pos[0] += 1;
                move = true;
            }
        }
        else if (toupper(c) == 'D')
        {
            if (pos[1] != 2) {
                pos[1] += 1;
                move = true;
            }
        }
    }
}