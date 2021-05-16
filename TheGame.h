#pragma once

#include "Board.h"
#include "Figure.h"
#include "Bomb.h"
#include "Menu.h"
#include <conio.h>
enum { ESC = 27 };//escape
enum { RAND = 7 };

class TheGame : public Figure
{
protected:
	Menu menu;
	Board GameBoard;
public:
	char LeftPlayerKeys[10] = { 'a','A','d','D','s','S','w','W','x','X' };
	char RightPlayerKeys[10] = { 'j','J','l','L','k','K','i','I','m','M' };
	TheGame() {}; //ctor
	void resetBoard()
	{
		GameBoard.initBoard();
	}
	general* createFigure(int numOfPlayer, int* serialNum,Board& board);
	virtual void RunGame(int Level1, int Level2);
	void clearKeyBoardBuffer()const;
	bool MoveFigure(Board& board, general& f, int serialNum, char direction);
	void getMenuInstructions()const
	{
		menu.ShowInstructions();
	}
	bool WinCheck(int NumPlayer)const;
	void HideCursor();

}; 
