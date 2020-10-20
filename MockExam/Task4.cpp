/**********************************************************************************************************
 *  @file    Task4.CPP
 *  @author  Benjamin A.E. Darici
 */
#include "Task3.h"  //  movement()
#include "Task4.h"  //  Task4(), drawGrid(), point()
#include <iostream> //  cout
#include <conio.h>  //  _getch()

//	A "main" function for Task 4
void Task4()
{
    system("CLS");
    int pos[2]{ 9,8 },
        score = 0;
    char grid[10][10] = {
        {'+','#','#','#','#','#','#','#','#','|'},
        {'|','X','.','.','.','.','.','.','.','|'},
        {'|','#','#','.','#','#','#','#','#','|'},
        {'|','.','.','.','.','.','.','.','.','|'},
        {'|','.','|','.','|','#','#','#','|','|'},
        {'|','.','|','.','|','.','.','.','|','|'},
        {'|','.','|','.','.','.','.','.','.','|'},
        {'|','.','.','.','.','.','.','.','.','|'},
        {'|','.','.','#','#','#','#','#','.','|'},
        {'|','_','_','_','_','_','_','_','_','|'}
    };

    do
    {
        point(pos, grid, score);
        drawGrid(pos, grid, score);
        movement(pos, grid);
        system("CLS");
    } while (grid[pos[0]][pos[1]] != 'X');
}

//  A function that draws the game grid, very similar to Task 3, but includes score
void drawGrid(const int(&pos)[2], const char(&grid)[10][10], const int score)
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
        if (i == 2) {
            std::cout << "Score: " << score;
        }
    }
}

//  A funtion that calculates points
void point(const int(&pos)[2], char(&grid)[10][10], int& score)
{
    if (grid[pos[0]][pos[1]] == '.')
    {
        grid[pos[0]][pos[1]] = ' ';
        score+=5;
    }
    return;
}
