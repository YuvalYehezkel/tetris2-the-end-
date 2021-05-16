#include "TheGame.h"
#include "general.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

void TheGame::RunGame(int Level1, int Level2)
{
	menu.printMenu();
	TheGame* game;

	//general* f1, * f2;
	char key_char = 0;
	int y1 = Y1;
	int y2 = Y2;
	//int serialNum1 = -1;
	//int serialNum2 = -1;


	HideCursor();
	if (_kbhit())
	{
		key_char = _getch();
		if (key_char == INSTRUCTIO_KEYS)
		{
			menu.ShowInstructions();
		}
		if (key_char == EXIT)
		{
			menu.ExitGame();
		}
		if (WinCheck(LEFT_PLAYER) == true || WinCheck(RIGHT_PLAYER) == true)
		{
			menu.StartNewGame(key_char, y1, y2, this->GameBoard);

		}
	}
}


bool TheGame::MoveFigure(Board& board, general& f, int serialNum, char direction) // קוראת לפונקציות תזוזה לפי המקשים
{
	if (direction == 'A' || direction == 'a' || direction == 'j' || direction == 'J')
	{

		return f.update(board, serialNum, LEFT, 1);

	}
	else if (direction == 'D' || direction == 'd' || direction == 'L' || direction == 'l')
	{
		return f.update(board, serialNum, RIGHT, 1);
	}
	else if (direction == 'K' || direction == 'k' || direction == 'S' || direction == 's')
	{
		return f.update(board, serialNum, CLOCKWISE, 1);
	}
	else if (direction == 'I' || direction == 'i' || direction == 'W' || direction == 'w')
	{
		return f.update(board, serialNum, COUNTERCLOCKWISE, 1);
	}
	else //if(direction == ' ' || direction == 'X' || direction == 'x' || direction == 'M' || direction == 'm')
	{

		return f.update(board, serialNum, DOWN, 1);
	}
}


general* TheGame::createFigure(int numOfPlayer, int* serialNum,Board& board)
{
	general* generalFigure = nullptr;
	int randNum = rand() % RAND;
	int randBomb = rand() % 20; 
	if (randBomb == 0)
	{
		generalFigure = new Bomb(numOfPlayer,board);
		*serialNum = BOMB;

	}
	else
	{
		switch (randNum)
		{
		case 0:
		{
			generalFigure = new Figure(LINE, numOfPlayer,board);
			*serialNum = LINE;

			break;

		}
		case 1:
		{
			generalFigure = new Figure(L, numOfPlayer,board);

			*serialNum = L;

			break;
		}
		case 2:
		{
			generalFigure = new Figure(RL, numOfPlayer,board);
			*serialNum = RL;

			break;
		}
		case 3:
		{
			generalFigure = new Figure(SQUARE, numOfPlayer,board);
			*serialNum = SQUARE;


			break;
		}
		case 4:
		{
			generalFigure = new Figure(RZ, numOfPlayer,board);
			*serialNum = RZ;


			break;
		}
		case 5:
		{
			generalFigure = new Figure(Z, numOfPlayer,board);
			*serialNum = Z;



			break;
		}
		case 6:
		{
			generalFigure = new Figure(PLUS, numOfPlayer,board);
			*serialNum = PLUS;

			break;
		}
		

		default:
		{
			break;
			//return  generalFigure;
		}
		}
	}
	return generalFigure;
}


void TheGame::clearKeyBoardBuffer()const
{
	char junk;
	while (_kbhit())
	{
		junk = _getch();
	}
}
bool TheGame::WinCheck(int NumPlayer)const
{
	bool IsLoser = false;
	if (NumPlayer == LEFT_PLAYER)
	{
		if (this->GameBoard.IsFull4(1, NumPlayer) == true)
			IsLoser = true;
		if (IsLoser == true)
		{
			gotoxy(4, 14);
			cout << "Player2 is the WINNER!";
		}
	}
	else
	{
		if (this->GameBoard.IsFull4(1, NumPlayer) == true)
			IsLoser = true;
		if (IsLoser == true)
		{
			gotoxy(4, 14);
			cout << "Player1 is the WINNER!";
		}
	}
	return IsLoser;
}
void TheGame::HideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);

}