// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>
#include <ctime> //for better rng
#include <iomanip>
#include <conio.h> //console input output header
#include <Windows.h>
#include "snake-game-Console.h"

using namespace std;
snakeGame::snakeGame() // insted of using the setup funciton using a constructor does itfaster.
{
    gameOver = false;
    dir = STOP;
    snekXY[0][0] = mapWidth / 2;
    snekXY[0][1] = mapHeight / 2;
    foodXY[0][0] = rand() % mapWidth;
    foodXY[0][1] = rand() % mapHeight;
    score = 0;
    snekSize = score + 1;
}


void snakeGame::Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
        }
    }
}

void snakeGame::Draw()
{
    bool drewAlredy = false;

    system("cls");

    //top part
    for (int x = 0; x <= mapWidth + 1; x++)
    {
        cout <<  "$";
    }

    cout << endl;
// the body of the map
    for (int y = 0; y <= mapHeight; y++)
    {
        for (int x = 0; x <= mapWidth + 1; x++)
        {

            drewAlredy = false; // resetting the variable
            if (x == 0 || x == mapWidth + 1)// checking for sidewalls, prefered to make it bigger than map width
            {
                cout << "$";
                drewAlredy = true;
            }
            //looping checks through all the segments
            for (int g = 0; g < snekSize; g++)
            {
                if (y == snekXY[g][1] && x == snekXY[g][0])
                {
                    cout << "s";
                    drewAlredy = true;
                }
            }
            //drawing the food and snake
            if (y == foodXY[0][1] && x == foodXY[0][0])
            {
                cout << "F";
                drewAlredy = true;
            }

            if(!drewAlredy)//if no drawing of anything happened, it must be empty space so space!
            {
                cout << " "; // middle of the map
            }
        }
        cout << endl;// space to next line for thhe loop 
    }
    //bottom wall
    for (int x = 0; x <= mapWidth + 1; x++)
    {
        cout << "$";
    }

    cout << "\n score : " << score << endl;
    
    /* to check coordinates with logic, TESTING ONLY
    cout << snekSize;
    for (int i = 0; i < snekSize; i++)
    {
        for (int j = 0; j < 2; j++) 
        {
            cout << "\n snek " << i << " : " << snekXY[i][j];
        }
    }*/ 
}
      

void snakeGame::logic()
{
    //for later assignment into each other
    int prevXY[50][2];// this is where the real efficiency comes
    for (int h = snekSize; h > -1; h--)
    {
        for (int k = 0; k < 2; k++)
        {
            prevXY[h][k] = snekXY[h][k];
        }
    }

    switch (dir)
    {
    case STOP:
        break;
    case LEFT:
        snekXY[0][0]--;
        break;
    case RIGHT:
        snekXY[0][0]++;
        break;
    case UP:
        Sleep(40);
        snekXY[0][1]--;
        break;
    case DOWN:
        Sleep(40);
        snekXY[0][1]++;
        break;
    }


    //wall control which will makke it wrap around
    if (snekXY[0][0] > mapWidth)
    {
        snekXY[0][0] = 0;
    }
    else if (snekXY[0][0] < 0)
    {
        snekXY[0][0] = mapWidth;
    }
    else if (snekXY[0][1] > mapHeight)
    {
        snekXY[0][1] = 0;
    }
    else if (snekXY[0][1] < 0)
    {
        snekXY[0][1] = mapHeight;
    }
    //food eating logic, randomize next spawn and increase score
    if (snekXY[0][0] == foodXY[0][0] &&
        snekXY[0][1] == foodXY[0][1])
    {
        score++;
        foodXY[0][0] = rand() % mapWidth;
        foodXY[0][1] = rand() % mapHeight;
        snekSize = score + 1;
    }
    //self eating logic
    for (int i = 1; i < snekSize; i++)
    {
        if (snekXY[0][0] == snekXY[i][0] && 
            snekXY[0][1] == snekXY[i][1])
        {
            gameOver = true;
        }


    }
    //follow logic snake
    for (int i = snekSize; i > 0; i--)//following thhe assigning of variables from the tail
    {
        snekXY[i][0] = prevXY[i - 1][0];
        snekXY[i][1] = prevXY[i - 1][1];
    }
}

void snakeGame::start()
{
    while (!gameOver)
    {
        Draw();
        Input();
        logic();
    }
    
   
}