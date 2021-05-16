#pragma once
#include "gotoxy.h"

class Point
{
	int x;
	int y;
	bool IsBusy;
	char ch; //the sign of the point
public:
	//ctor
	Point() {};

	//setters

	void SetPoint(int _x, int _y, bool _IsBusy, char _ch)
	{
		x = _x;
		y = _y;
		IsBusy = _IsBusy;
		ch = _ch;
	};
	void Set_X(int _x)
	{
		x = _x;
	}
	void Set_Y(int _y)
	{
		y = _y;
	}
	void SetIsBusy(bool _IsBusy)
	{
		IsBusy = _IsBusy;
	}
	//getters
	int getX()const
	{
		return x;
	}
	int gety()const
	{
		return y;
	}
	char getChar()const
	{
		return ch;
	}
	bool getIsBusy()const
	{
		return IsBusy;
	}
	void SetChar(char _ch)
	{
		ch = _ch;
	}
}; 
