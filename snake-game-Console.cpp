// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>
#include <ctime> //for better rng
#include <iomanip>
#include <conio.h> //console input output header

using namespace std;
//global variable
bool gameOver;
const int mapWidth = 40;
const int mapHeight = 20;
int snekX[50], snekY[50];
int foodX, foodY;
int snekSize;
int score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    snekX[0] = mapWidth/2;
    snekY[0] = mapHeight / 2;
    foodX = rand() % mapWidth;
    foodY = rand() % mapHeight;
    score = 0;
    snekSize = 1;
    
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
    bool drewAlredy = false;

    system("cls");

    //top part
    for (int x = 0; x <= mapWidth + 2; x++)
    {
        cout <<  "$";
    }

    cout << setw(mapWidth) << "score : " << score;

    cout << endl;
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
                if (y == snekY[g] && x == snekX[g])
                {
                    cout << "S";
                    drewAlredy = true;
                }
            }
            //drawing the food and snake
            if (y == foodY && x == foodX)
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
    for (int x = 0; x <= mapWidth + 2; x++)
    {
        cout << "$";
    }

}

void logic()
{
    //for later assignment into each other
    int prevX[50], prevY[50];
    for (int h = snekSize; h > -1; h--)
    {
        prevX[h] = snekX[h];
        prevY[h] = snekY[h];
    }
    
    switch (dir)
    {
    case STOP:
        break;
    case LEFT:
        snekX[0]--;
        break;
    case RIGHT:
        snekX[0]++;
        break;
    case UP: 
        snekY[0]--;
        break; 
    case DOWN:
        snekY[0]++;
        break;
    }


    //wall control
    if (snekX[0] > mapWidth ||
        snekX[0] < 0 ||
        snekY[0] > mapHeight ||
        snekY[0] < 0)
    {
        gameOver = true;
    }
    //food eating logic, randomize next spawn and increase score
    if (snekY[0] == foodY &&
        snekX[0] == foodX)
    {
        score++;
        foodX = rand() % mapWidth;
        foodY = rand() % mapHeight;
        snekSize++;
    }

    //follow logic snake
    for (int i = snekSize; i > 0; i--)//following thhe assigning of variables from the tail
    {
        snekX[i] = prevX[i - 1];
        snekY[i] = prevY[i - 1 ];
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

