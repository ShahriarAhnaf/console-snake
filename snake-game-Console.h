#pragma once
#include "snek.h"

class snakeGame
{
public:
	snakeGame();
	void start(); //used for proper encapsulation of functiions
private:
	void Draw();
	void logic();
	void Input();
public:
	//objects
	snek snek;
	//global variable
	const int mapWidth = 40;
	const int mapHeight = 10;
	int score;
	int foodXY[1][1];// 0 = x, y = 1 for assignment
};