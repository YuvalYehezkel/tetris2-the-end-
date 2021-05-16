#include "ComputerVsComputer.h"


void ComputerVsComputer::RunGame(int Level1, int Level2)
{
	TheGame::RunGame(Level1, Level2);
	general* f1, * f2;
	char key_char = 0;
	int y1 = Y1;
	int y2 = Y2;

	int serialNum1 = -1;
	int serialNum2 = -1;
	f1 = createFigure(LEFT_PLAYER, &serialNum1, this->GameBoard);

	f2 = createFigure(RIGHT_PLAYER, &serialNum2, this->GameBoard);
	int randLevel1 = 1;
	int randLevel2 = 1;
	if (Level1 == '2')
	{
		randLevel1 = rand() % 40;
	}
	else if (Level1 == '3')
	{
		randLevel1 = rand() % 10;
	}
	if (Level2 == '2')
	{
		randLevel1 = rand() % 40;
	}
	else if (Level2 == '3')
	{
		randLevel1 = rand() % 10;
	}

	while (key_char != EXIT && (!WinCheck(LEFT_PLAYER)) && (!WinCheck(RIGHT_PLAYER)))
	{


		f1->print(this->GameBoard);
		Sleep(100);


		f2->print(this->GameBoard);
		Sleep(100);

		
		if (randLevel1 == 0 && y1 == 1)
		{
			RandMove(f1, LEFT_PLAYER);
		}
		else
		{
			if (y1 == 1)
			{
				FindTheBestPlacementOfFigure(f1, LEFT_PLAYER, Level1);
			}
		}
		if (randLevel2 == 0 && y2 == 1)
		{
			RandMove(f2, RIGHT_PLAYER);
		}
		else
		{
			if (y2 == 1)
			{
				FindTheBestPlacementOfFigure(f2, RIGHT_PLAYER, Level1);
			}
		}

		++y1;
		++y2;

		if (_kbhit())
		{
			key_char = _getch();
			if (key_char == INSTRUCTIO_KEYS)
			{
				gotoxy(0, ROWS + 7);
				menu.ShowInstructions();
			}
			else if (key_char == ESC)
			{
				menu.ContinuePausedGame(key_char, this->GameBoard);
				menu.printMenu();
			}
			else if (key_char == EXIT)
			{
				menu.ExitGame();
			}
		}

		clearKeyBoardBuffer();
		if (f1->update(this->GameBoard, serialNum1, DOWN, 1) == false || y1 > ROWS)
		{
			y1 = 1;
			GameBoard.DeleteRow(LEFT_PLAYER);
			delete f1;
			f1 = createFigure(LEFT_PLAYER, &serialNum1, this->GameBoard);
			if (Level1 == '2')
			{
				randLevel1 = rand() % 40;
			}
			else if (Level1 == '3')
			{
				randLevel1 = rand() % 10;
			}
		}

		if (f2->update(this->GameBoard, serialNum2, DOWN, 1) == false || y2 > ROWS)
		{
			y2 = 1;
			GameBoard.DeleteRow(RIGHT_PLAYER);
			delete f2;
			f2 = createFigure(RIGHT_PLAYER, &serialNum2, this->GameBoard);
			if (Level2 == '2')
			{
				randLevel2 = rand() % 40;
			}
			else if (Level2 == '3')
			{
				randLevel2 = rand() % 10;
			}
		}
	}
}
