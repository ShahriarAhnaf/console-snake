#pragma once
class snek
{
private:
	//functions
	//variables
	
public:
	//funcctions
	void Input();
	void follow();
	void selfEat();
	void WallControl(int mapWidth, int mapHeight);
	void assignPrevXY();
	//variables
	int snekXY[50][2];// 50 rows, 2 coloums
	bool gameOver = false;
	int snekSize;
	int prevXY[50][2];
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir = STOP;
};

