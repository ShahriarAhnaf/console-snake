// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h> //console input output header

using namespace std;
//global variable
bool gameOver;
const int mapWidth = 40;
const int mapHeight = 20;
int snekX, snekY;
int foodX, foodY;
int snekSize;
int score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    snekX = mapWidth/2;
    snekY = mapHeight / 2;
    foodX = rand() % mapWidth;
    foodY = rand() % mapHeight;
    score = 0;

}

void Input()
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

void Draw()
{
    system("cls");
    //top part
    for (int x = 0; x <= mapWidth + 1; x++)
    {
        cout <<  "$";
    }
    cout << endl;
    for (int y = 0; y <= mapHeight; y++)
    {
        for (int x = 0; x <= mapWidth + 1; x++)
        {
            if (x == 0 || x == mapWidth + 1 )// checking for sidewalls, prefered to make it bigger than map width
            {
                cout << "$";
            }
            //drawing the food and snake
            if (y == foodY && x == foodX)
            {
                cout << "F";
            }
            else if (y == snekY && x == snekX)
            {
                cout << "S";
            }
            else
            {
                cout << " "; // middle of the map
            }
        }
        cout << endl;
    }
    //bottom wall
    for (int x = 0; x <= mapWidth + 1; x++)
    {
        cout << "$";
    }
}

void logic()
{
    switch (dir)
    {
    case STOP:
        break;
    case LEFT:
        snekX--;
        break;
    case RIGHT:
        snekX++;
        break;
    case UP: 
        snekY--;
        break; 
    case DOWN:
        snekY++;
        break;
    }


    //wall control
    if (snekX > mapWidth ||
        snekX < 0 ||
        snekY > mapHeight||
        snekY < 0)
    {
        gameOver = true;
    }
}

int main()
{

    Setup(); // must be called outside
    while (!gameOver)
    {
        Draw();
        Input();
        logic();
    }
}

