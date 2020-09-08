// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>



using namespace std;
//global variable
bool gameOver;
const int mapWidth = 25;
const int mapHeight = 25;
int x, y;
int foodx, foody;
int snekSize;
int score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    int x = mapWidth/2;
    int y = mapHeight / 2;
    foodx = rand() % mapWidth;
    foody = rand() % mapHeight;
    score = 0;

}

void Input()
{

}

void Draw()
{
    system("cls");
    for (int y = 0; y <= mapHeight; y++)
    {
        for (int x = 0; x <= mapWidth; x++)
        {
            if (x == 0 || x == mapWidth)
            {
                cout << "$";

            }
            else if (y == 0 || y == mapHeight)
            {
                cout << "$";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

    }
}

void logic()
{

}

int main()
{
    while (!gameOver)
    {
        Draw();
        Input();
        logic();
    }
}

