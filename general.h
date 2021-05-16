#pragma once
#include "Point.h"
#include "Board.h"

class general {
	
public:
	
	general() {}; //ctor
	virtual ~general() {};
	virtual bool update(Board& board,int serialNum, int dir, int numFunc) = 0;
	virtual void print(Board& board) = 0;
	virtual int getSerial()const = 0;
	virtual Point* getBodyPos() = 0;
	virtual int getSize()const = 0;
	virtual int getRotateNum()const = 0;
	virtual void setBodyPos(Point* _FigureBody) = 0;
}; 
