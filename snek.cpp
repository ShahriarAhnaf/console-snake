#include "snek.h"
#include <conio.h>
#include <Windows.h>

void snek::Input()
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

    //
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
}

void snek::follow()
{
    for (int i = snekSize; i > 0; i--)//following thhe assigning of variables from the tail
    {
        snekXY[i][0] = prevXY[i - 1][0];
        snekXY[i][1] = prevXY[i - 1][1];
    }
}

void snek::selfEat()
{
    for (int i = 1; i < snekSize; i++)
    {
        if (snekXY[0][0] == snekXY[i][0] &&
            snekXY[0][1] == snekXY[i][1])
        {
            gameOver = true;
        }
    }
}

void snek::WallControl(const int mapWidth, const int mapHeight)
{
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
}

void snek::assignPrevXY()
{
    for (int h = snekSize; h > -1; h--)
    {
        for (int k = 0; k < 2; k++)
        {
            prevXY[h][k] = snekXY[h][k];
        }
    }
}
