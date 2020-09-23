// snake-game-Console.cpp : This file contains the 'main' function. 
// no object oriented programming yet

#include <iostream>
#include <cstdlib>
#include <ctime> //for better rng
#include <iomanip>
#include "snake-game-Console.h"

using namespace std;
snakeGame::snakeGame() // insted of using the setup funciton using a constructor does itfaster.
{
    snek.snekXY[0][0] = mapWidth / 2;
    snek.snekXY[0][1] = mapHeight / 2;
    foodXY[0][0] = rand() % mapWidth;
    foodXY[0][1] = rand() % mapHeight;
    score = 0;
    snek.snekSize = score + 1;
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
            for (int g = 0; g < snek.snekSize; g++)
            {
                if (y == snek.snekXY[g][1] && x == snek.snekXY[g][0])
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
    // this is where the real efficiency comes
    snek.assignPrevXY();

    //wall control which will makke it wrap around
    snek.WallControl(mapWidth, mapHeight);
    //food eating logic, randomize next spawn and increase score

    if (snek.snekXY[0][0] == foodXY[0][0] &&
        snek.snekXY[0][1] == foodXY[0][1])
    {
        score++;
        foodXY[0][0] = rand() % mapWidth;
        foodXY[0][1] = rand() % mapHeight;
        snek.snekSize = score + 1;
    }
    //self eating logic
    snek.selfEat();
    //follow logic snake
    snek.follow();
}

void snakeGame::start()
{
    while (!snek.gameOver)
    {
        Draw();
        snek.Input();
        logic();
    }
    
   
}