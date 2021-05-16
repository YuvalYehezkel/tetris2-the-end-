#pragma once
#include "Figure.h"
#include "Board.h"
#include "general.h"

class Bomb : public general
{
	Point bomb;
	int serialNum = BOMB;
	int explodeSquareCounter = 0;
	
public:
	Bomb() {}
	virtual ~Bomb() {};
	Bomb(int playerNum,Board& board) {
		if (playerNum == LEFT_PLAYER)
		{
			initBomb(X1, Y1);
		}
		else if (playerNum == RIGHT_PLAYER)
		{
			initBomb(X2, Y2);
		}
	}
	void initBomb(int x, int y);
	bool update(Board& board,int serialNum, int dir, int numFunc) override;
	void explodeBomb(Board& board, int numFunc);
	void print(Board& board) override;
	virtual int getSerial()const
	{
		return serialNum;
	}
	virtual Point* getBodyPos()
	{
		return &bomb;
	}
	virtual int getSize()const
	{
		return 1;
	}
	virtual int getRotateNum()const
	{
		return 0;
	}
	virtual void setBodyPos(Point* _FigureBody)
	{
		bomb = *_FigureBody;
	}
	int getExplodeNum()const
	{
		return explodeSquareCounter;
	}



}; 
