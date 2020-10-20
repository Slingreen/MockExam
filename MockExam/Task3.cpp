/**********************************************************************************************************
 *  @file    Task3.CPP
 *  @author  Benjamin A.E. Darici
 */
#include "Task3.h"  //  Task3(), drawGrid(), movement()
#include <iostream> //  toupper(), cout, endl
#include <conio.h>  //  _getch()

 //	A "main" function for Task 3
void Task3()
{
    system("CLS");
    int pos[2]{ 9,8 };
    char grid[10][10] = {
        {'+','#','#','#','#','#','#','#','#','|'},
        {'|','X',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|','#','#',' ','#','#','#','#','#','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ','|',' ','|','#','#','#','|','|'},
        {'|',' ','|',' ','|',' ',' ',' ','|','|'},
        {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ','#','#','#','#','#',' ','|'},
        {'|','_','_','_','_','_','_','_','_','|'}
    };

    do
    {
        drawGrid(pos, grid);
        movement(pos,grid);
        system("CLS");
    } while (grid[pos[0]][pos[1]]!='X');
}

//  A function that draws the game grid
void drawGrid(int(&pos)[2], char(&grid)[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 10; j++)
        {
            if (i == pos[0] && j == pos[1]) {
                std::cout << "E";
            }
            else
            {
                std::cout << grid[i][j];
            }
        }
    }
}

//  Movement options for the game grid
void movement(int(&pos)[2], char(&grid)[10][10])
{
    char c;
    bool move = false;
    while (!move)
    {
        c = _getch();
        if (toupper(c) == 'W' )
        {
            if (pos[0] != 0 && grid[pos[0]-1][pos[1]]!='#' && grid[pos[0]-1][pos[1]] != '|') {
                pos[0] -= 1;
                move = true;
            }
        }
        else if (toupper(c) == 'A')
        {
            if (pos[1] != 0 && grid[pos[0]][pos[1]-1] != '#' && grid[pos[0]][pos[1]-1] != '|') {
                pos[1] -= 1;
                move = true;
            }
        }
        else if (toupper(c) == 'S')
        {
            if (pos[0] != 9 && grid[pos[0]+1][pos[1]] != '#' && grid[pos[0]+1][pos[1]] != '|') {
                pos[0] += 1;
                move = true;
            }
        }
        else if (toupper(c) == 'D')
        {
            if (pos[1] != 9 && grid[pos[0]][pos[1]+1] != '#' && grid[pos[0]][pos[1]+1] != '|') {
                pos[1] += 1;
                move = true;
            }
        }
    }
}