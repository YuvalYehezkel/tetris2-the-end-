#pragma once


class BotMovesGrade
{
	int DeletedLines=0;
	int Height=0;
	int bestcol;
public:
	void SetHeight(int _height)
	{
		Height = _height;
	}
	void SetDeletedLines(int _deletedLines)
	{
		DeletedLines = _deletedLines;
	}
	void Setbestcol(int _BestCol)
	{
		bestcol = _BestCol;
	}
	int GetHeight()const
	{
		return Height;
	}
	int GetDeletedLines()const
	{
		return DeletedLines;
	}
	int Getbestcol()const
	{
		return bestcol;
	}
};
