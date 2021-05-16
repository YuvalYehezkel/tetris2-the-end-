#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

enum { ROWS = 18, COLS = 12};
enum { SIGN = -37 };
enum { LEFT_PLAYER = 1, RIGHT_PLAYER = 2 };
class Board
{

	Point GameBoard[ROWS + 2][COLS * 2 + 3];
public:
	//ctor
	Board();
	void initBoard();
	bool isValidPoint(int a, int b)const
	{
		if ((!GameBoard[b][a].getIsBusy()) && (GameBoard[b][a].getChar() != '*') && ((a >= 1 && a <= COLS) || (a >= COLS + 2 && a <= 2 * COLS + 1)) && (b >= 1 && b <= ROWS))
			return true;
		return false;
	}
	bool isValidPointForBomb(int a, int b)const
	{
		if ((GameBoard[b][a].getChar() == SIGN) && ((a >= 1 && a <= COLS) || (a >= COLS + 2 && a <= 2 * COLS + 1)) && (b >= 1 && b <= ROWS))
			return true;
		return false;
	}
	void turnToBusyPoint(int x, int y, char ch = SIGN)
	{
		gotoxy(x, y);
		cout << ch;
		GameBoard[y][x].SetPoint(x, y, true, ch);
	}
	void turnToFreePoint(int x, int y, char ch = ' ')
	{
		gotoxy(x, y);
		cout << ch;
		GameBoard[y][x].SetPoint(x, y, false, ch);
	}
	bool IsFullRow(int RowNum, int NumPlayer)const;
	bool IsEmptyRow(int RowNum, int NumPlayer)const;
	bool IsFull4(int RowNum, int NumPlayer)const;
	void DeleteRow(int NumPlayer);
	void DropLines(int FreeRow, int NumPlayer);
	void PrintBoard()const;
}; 
