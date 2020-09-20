#pragma once
class snakeGame
{
public:
	snakeGame();
	void start(); //used for proper encapsulation of functiions
private:
	void Setup();
	void Draw();
	void logic();
	void Input();
public:
	//global variable
	bool gameOver = false;
	const int mapWidth = 40;
	const int mapHeight = 10;
	int snekXY[50][2];// 50 rows, 2 coloums
	int foodXY[1][1];// 0 = x, y = 1 for assignment
	int snekSize;
	int score;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
};