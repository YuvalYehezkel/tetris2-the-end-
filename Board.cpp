#include "Board.h"
#include "gotoxy.h"

Board::Board()
{
	initBoard();
}

void Board::initBoard()
{
	for (int i = 0; i < ROWS + 2; i++)
	{
		for (int j = 0; j < 2 * COLS + 3; j++)
		{
			if (i == 0 || i == ROWS + 1 || j == 0 || j == COLS + 1 || j == (2 * COLS) + 2)
			{
				turnToBusyPoint(j, i, '*');

			}
			else
			{
				turnToFreePoint(j, i, ' ');
			}
		}
	}
}


bool Board::IsFullRow(int RowNum, int NumPlayer)const
{
	bool FullRow = true;
	int startVal, endVal;
	if (NumPlayer == LEFT_PLAYER)
	{
		startVal = 1;
		endVal = COLS;
	}
	else
	{
		startVal = COLS + 2;
		endVal = 2 * COLS + 1;
	}
	for (int i = startVal; i <= endVal; i++)
	{
		if ((GameBoard[RowNum][i].getChar() ) == ' ')
		{
			FullRow = false;
			break;
		}
	}
	return FullRow;
}

bool Board::IsEmptyRow(int RowNum, int NumPlayer)const
{
	bool emptyRow = true;
	int startVal, endVal;
	if (NumPlayer == LEFT_PLAYER)
	{
		startVal = 1;
		endVal = COLS;
	}
	else
	{
		startVal = COLS + 2;
		endVal = 2 * COLS + 1;
	}
	for (int i = startVal; i <= endVal; i++)
	{
		if (GameBoard[RowNum][i].getChar() == SIGN)
		{
			emptyRow = false;
			break;
		}
	}
	return emptyRow;
}


bool Board::IsFull4(int RowNum, int NumPlayer)const
{
	bool Full4 = false;
	int startVal, endVal;
	if (NumPlayer == LEFT_PLAYER)
	{
		startVal = 5;
		endVal = 8;
	}
	else
	{
		startVal = 18;
		endVal = 21;
	}
	for (int i = startVal; i <= endVal; i++)
	{
		if (GameBoard[RowNum][i].getChar() != ' ')//מספיק שאחד מהם מלא ויחזיר טרו ויש הפסד
		{
			Full4 = true;
			break;
		}
	}
	return Full4;
}
void Board::DeleteRow(int NumPlayer)
{

	for (int i = ROWS; i>0; i--)
	{
		if (IsFullRow(i, NumPlayer))
		{
			if (NumPlayer == LEFT_PLAYER)
			{
				for (int j = 1; j <= COLS; j++)
				{
					turnToFreePoint(j, i, ' ');
				}
			}
			else
			{
				for (int j = COLS + 2; j <= COLS * 2 + 1; j++)
				{
					turnToFreePoint(j, i, ' ');
				}

			}
			DropLines(i, NumPlayer);
		}
	}

}
void Board::DropLines(int FreeRow, int NumPlayer)
{
	for (int i = FreeRow; i > 1; i--)
	{
		if (NumPlayer == LEFT_PLAYER)
		{
			for (int j = 1; j <= COLS; j++)
			{
				this->GameBoard[i][j].SetChar(this->GameBoard[i - 1][j].getChar());
				this->GameBoard[i][j].SetIsBusy(this->GameBoard[i - 1][j].getIsBusy());
				gotoxy(j, i);
				cout << this->GameBoard[i][j].getChar();
			}

		}

		else
		{
			for (int j = COLS + 2; j <= 2 * COLS + 1; j++)
			{
				this->GameBoard[i][j].SetChar(this->GameBoard[i - 1][j].getChar());
				this->GameBoard[i][j].SetIsBusy(this->GameBoard[i - 1][j].getIsBusy());
				gotoxy(j, i);
				cout << this->GameBoard[i][j].getChar();
			}

		}
	}
}
void Board::PrintBoard()const
{
	for (int i = 0; i < ROWS + 2; i++)
	{
		for (int j = 0; j < 2 * COLS + 3; j++)
		{
			gotoxy(j, i);
			cout << this->GameBoard[i][j].getChar();
		}
	}

}