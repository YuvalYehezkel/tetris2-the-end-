#pragma once
#include "TheGame.h"
#include "BotMovesGrade.h"
#include "windows.h"
class Computer : public TheGame
{
protected:
	BotMovesGrade calculatePos;
	char Level = '\0';
public:
	Computer(){}
	void ChooseComputerLevel();
	void FindTheBestPlacementOfFigure(general* f, int NumPlayer, int Level1);
	void FindTheBestPlacementOfBomb(general* f, int NumPlayer);
	int HowManyDeletedLines(Board& board, int NumPlayer) const;
	int calculateTheHeightOfCurrPlacement(general* f) const;
	int LowColOfCurrPlacement(general* f);
	int compareBetween2Placements(int maxHeight1, int maxHeight2, int numDeletedRows1, int numDeletedRows2, int* BestHeight, int* BestRow, int Col1, int Col2);
	int compareRotations(BotMovesGrade* position, int size);
	void CompareFuncForBomb(int* maxExplodedNum, int currExplodedNum, int* bestcol, int col);
	void setLevel(char _level)
	{
		Level = _level;
	}
	char getLevel()const
	{
		return Level;
	}
	void RandMove(general* f, int NumPlayer);
	
};