// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>
#include <iomanip>


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
        for (int x = 0; x <= mapWidth; x++)
        {
            if (x == 0 || x == mapWidth )// checking for sidewalls
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

