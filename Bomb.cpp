#include "Bomb.h"
using namespace std;


void Bomb::initBomb(int x, int y)
{
	bomb.SetPoint(x, y, true, '$');
	
}
bool Bomb::update(Board& board, int serialNum, int dir, int numFunc)
{
	switch (dir)
	{
	case direction::DOWN:
	{
		if (board.isValidPoint(bomb.getX(), bomb.gety() + 1))
		{
			board.turnToFreePoint(bomb.getX(), bomb.gety());
			bomb.SetPoint(bomb.getX(), bomb.gety() + 1, true, bomb.getChar());
			board.turnToBusyPoint(bomb.getX(), bomb.gety(), '$');
		}
		else if (numFunc == 1)
		{
			explodeBomb(board, 1);
			return false;
		}
		else if (numFunc == 2)
		{
			return false;
		}
		break;
	}
	case direction::LEFT:
	{
		if (board.isValidPoint(bomb.getX() - 1, bomb.gety()))
		{
			board.turnToFreePoint(bomb.getX(), bomb.gety());
			bomb.SetPoint(bomb.getX() - 1, bomb.gety(), true, bomb.getChar());
		}
		else if (numFunc == 1)
		{
			explodeBomb(board, 1);
			return false;
		}
		else if (numFunc == 2)
		{
			return false;
		}
		break;
	}
	case direction::RIGHT:
	{
		if (board.isValidPoint(bomb.getX() + 1, bomb.gety()))
		{
			board.turnToFreePoint(bomb.getX(), bomb.gety());
			bomb.SetPoint(bomb.getX() + 1, bomb.gety(), true, bomb.getChar());
		}
		else if (numFunc == 1)
		{
			explodeBomb(board, 1);
			return false;
		}
		else if(numFunc == 2)
		{
			return false;
		}
		
		break;
	}
	}
	return true;
}

void Bomb::explodeBomb(Board& board,int numFunc)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board.isValidPointForBomb(bomb.getX() - 4 + i, bomb.gety() - 4 + j))
			{
				explodeSquareCounter++;
				if (numFunc == 1)
				{
					board.turnToFreePoint(bomb.getX() - 4 + i, bomb.gety() - 4 + j);
				}
			}

		}
	}
	
	board.turnToFreePoint(bomb.getX(), bomb.gety());
	
}
void Bomb::print(Board& board)
{
	board.turnToBusyPoint(bomb.getX(), bomb.gety(), bomb.getChar());
}