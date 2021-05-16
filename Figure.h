#pragma once
#include "general.h"
enum SHAPES { LINE = 0, L = 1, RL = 2, SQUARE = 3, Z = 4, RZ = 5, PLUS = 6, BOMB = 7 };//RT=reversed T=  *
																	 //=          *** 
enum startValue { X1 = 5, Y1 = 1, X2 = 18, Y2 = 1 };
enum direction { LEFT = 1, RIGHT = 2, DOWN = 3, CLOCKWISE = 4, COUNTERCLOCKWISE = 5 };
class Figure : public general
{
protected:
	enum { SIZE = 4 };
	Point* FigureBody;
	int RotateNum = 0;
	int Serial = 0;
public:
	virtual ~Figure()
	{
		delete FigureBody;
	}
	//// empty ctor
	Figure()
	{

	}
	Figure(int serialNum, int playerNum,Board& board)
	{
		FigureBody = new Point[SIZE];
		if (playerNum == LEFT_PLAYER)
		{
			initFigureBySerialNum(serialNum, X1, Y1,board);
		}
		else if (playerNum == RIGHT_PLAYER)
		{
			initFigureBySerialNum(serialNum, X2, Y2,board);
		}


	};
	
	virtual int getSerial() const
	{
		return Serial;
	}
	virtual void setSerial(int num)
	{
		Serial = num;
	}
	void setRotateNum(int num)
	{
		RotateNum = num;
	}
	int getRotateNum()const
	{
		return RotateNum;
	}


	void initFigureBySerialNum(int serialNum, int x, int y,Board& board);
	virtual void print(Board& board);
	virtual bool update(Board& board, int serialNum, int dir, int numFunc);
	bool updateFigureDrop(Board& board, int serialNum);
	bool updateFigureLeft(Board& board, int serialNum);
	bool updateFigureRight(Board& board, int serialNum);
	bool updateFigureRotateClockWise(Board& board, int serialNum);
	bool updateFigureRotateCounterClockWise(Board& board, int serialNum);
	virtual Point* getBodyPos()
	{
		return FigureBody;
	}
	virtual int getSize()const
	{
		return SIZE;
	}
	virtual void setBodyPos(Point* _FigureBody)
	{
		for (int i = 0; i < SIZE; i++)
		{
			FigureBody[i].SetPoint(_FigureBody[i].getX(), _FigureBody[i].gety(), _FigureBody[i].getIsBusy(), _FigureBody[i].getChar());
		}
	}


};

