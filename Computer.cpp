#include "Computer.h"

void Computer::ChooseComputerLevel()
{
	char key_char = 0;
	gotoxy(30, 10);
	cout << "for the BEST level press (1)" << endl;
	gotoxy(30, 11);
	cout << "for the GOOD level press (2)" << endl;
	gotoxy(30, 12);
	cout << "for the NOVICE level press (3)" << endl;

	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			setLevel(key_char);
			break;
		}
	}
}

void Computer::FindTheBestPlacementOfFigure(general* f, int NumPlayer, int Level1)
{
	if (f->getSerial() == BOMB && Level1 == '1')
	{
		FindTheBestPlacementOfBomb(f, NumPlayer);
	}
	else if (f->getSerial() == BOMB)
	{
		RandMove(f, NumPlayer);
	}
	else
	{

		Figure* temp = new Figure(f->getSerial(),NumPlayer, GameBoard);

		bool res;
		int counterDeletedLines1 = 0;
		int counterDeletedLines2 = 0;
		int maxHeight1; // height of the figure in the row
		int maxHeight2;
		int curHeight, BestHeigt;
		int BestRow; //the placement that delete to most rows
		int BestCol, Col1, Col2;
		BotMovesGrade Pos[SIZE];


		for (int i = 0; i < SIZE; i++)
		{

			while (temp->update(GameBoard, temp->getSerial(), LEFT, 1)){}
			//temp->print(GameBoard);
			//Sleep(100);
			
			Col1 = LowColOfCurrPlacement(temp);
			while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)){}
			//temp->print(GameBoard);


			counterDeletedLines1=BestRow = HowManyDeletedLines(GameBoard, NumPlayer); //we calculate how many lines the current figure drops

			maxHeight1=BestHeigt = calculateTheHeightOfCurrPlacement(temp); // the Height of the figure in current placement

			res=temp->update(GameBoard, temp->getSerial(), RIGHT, 1);

			while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)) {
				//temp->print(GameBoard);
			}
			Col2 = LowColOfCurrPlacement(temp);
			

			counterDeletedLines2 = HowManyDeletedLines(GameBoard, NumPlayer);
			maxHeight2 = calculateTheHeightOfCurrPlacement(temp);
			BestCol = compareBetween2Placements(BestHeigt, maxHeight2, BestRow, counterDeletedLines2, &BestHeigt, &BestRow, Col1, Col2);

			
			//right
			while (temp->update(GameBoard, temp->getSerial(), RIGHT, 1))
			{
				//temp->print(GameBoard);

				Col2 = LowColOfCurrPlacement(temp);
				while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)){
					//temp->print(GameBoard);
				}

				counterDeletedLines2 = HowManyDeletedLines(GameBoard, NumPlayer);
				maxHeight2 = calculateTheHeightOfCurrPlacement(temp);
				BestCol = compareBetween2Placements(BestHeigt, maxHeight2, BestRow, counterDeletedLines2, &BestHeigt, &BestRow, BestCol, Col2);
			}
			Pos[i].Setbestcol(BestCol);
			Pos[i].SetDeletedLines(BestRow);
			Pos[i].SetHeight(BestHeigt);

			delete temp;
			Figure* temp = new Figure(f->getSerial(), NumPlayer, GameBoard);
			temp->update(GameBoard, temp->getSerial(), CLOCKWISE, 1);

		}
		delete temp;
		int besRotation = compareRotations(Pos, SIZE);
		
		while (f->getRotateNum() != besRotation)
		{
		    f->update(GameBoard, f->getSerial(), CLOCKWISE, 1);
			f->print(GameBoard);

			Sleep(100);
		}
		
		while (LowColOfCurrPlacement(f) < Pos[besRotation].Getbestcol())
		{
			f->update(GameBoard, f->getSerial(), RIGHT, 1);
			f->print(GameBoard);
			Sleep(100);
		}
		while (LowColOfCurrPlacement(f) > Pos[besRotation].Getbestcol())
		{
			f->update(GameBoard, f->getSerial(), LEFT, 1);
			f->print(GameBoard);
			Sleep(100);

		}
	}
}

void Computer::FindTheBestPlacementOfBomb(general* f, int NumPlayer)
{
	int maxExplodedCounter;
	int currExplodedCounter;
	int bestCol;
	int currCol;
	Bomb* tempBomb = new Bomb(NumPlayer,GameBoard);
	while(tempBomb->update(GameBoard,BOMB,LEFT, 2)){}

	while (tempBomb->update(GameBoard, BOMB, DOWN, 2)) {}
	tempBomb->explodeBomb(GameBoard, 2);
	maxExplodedCounter = tempBomb->getExplodeNum();
	bestCol = tempBomb->getBodyPos()->getX();

	tempBomb->update(GameBoard, tempBomb->getSerial(), RIGHT, 2);
	while (tempBomb->update(GameBoard, BOMB, DOWN, 2)) {}

	tempBomb->explodeBomb(GameBoard, 2);

	currExplodedCounter = tempBomb->getExplodeNum();
	currCol = tempBomb->getBodyPos()->getX();

	CompareFuncForBomb(&maxExplodedCounter,currExplodedCounter,&bestCol, currCol);

	while (tempBomb->update(GameBoard, BOMB, RIGHT, 2))
	{
		while (tempBomb->update(GameBoard,BOMB, DOWN, 2)) {}
		tempBomb->explodeBomb(GameBoard, 2);

		currExplodedCounter= tempBomb->getExplodeNum();
		currCol = tempBomb->getBodyPos()->getX();
		
		CompareFuncForBomb(&maxExplodedCounter, currExplodedCounter, &bestCol, currCol);
	}

	delete tempBomb;
	
	while (bestCol > f->getBodyPos()->getX())
	{
		f->update(GameBoard, BOMB, RIGHT, 2);
		f->print(GameBoard);
		Sleep(100);
	}
	while (bestCol < f->getBodyPos()->getX())
	{
		f->update(GameBoard, BOMB, LEFT, 2);
		f->print(GameBoard);
		Sleep(100);
	}
}

void Computer::CompareFuncForBomb(int* maxExplodedNum, int currExplodedNum,int* bestcol,int col)
{
	if (currExplodedNum > * maxExplodedNum)
	{
		*maxExplodedNum = currExplodedNum;
		*bestcol = col;
	}
}

int Computer::compareRotations(BotMovesGrade* position, int size)
{
	int maxHeight=position[0].GetHeight();
	int bestRows= position[0].GetDeletedLines();
	int bestCol = position[0].Getbestcol();
	int bestRotation=0; 

	for (int i = 1; i < size ; i++)
	{
	
		bestRotation=compareBetween2Placements(maxHeight,position[i].GetHeight(), bestRows,position[i].GetDeletedLines(), &maxHeight, &bestRows,bestRotation,i);
	}
	return bestRotation;
}

int Computer::HowManyDeletedLines(Board& board, int NumPlayer) const//we calculate how many lines the current figure drops
{
	int counterDeletedLines = 0;
	for (int i = ROWS; i > 0; i--)
	{
		if (board.IsFullRow(i, NumPlayer))
		{
			counterDeletedLines++;
		}

	}
	return counterDeletedLines;
}

int Computer::calculateTheHeightOfCurrPlacement(general* f) const
{
	Point* body = f->getBodyPos();
	int maxHeight; // height of the figure in the row
	int curHeight;

	for (int j = 0; j < 4; j++) // we calculate the hight of the figure
	{
		curHeight = body[j].gety();
		if (j == 0)
		{
			maxHeight = curHeight;
		}
		if (curHeight < maxHeight)
		{
			maxHeight = curHeight; // when the height is smaller the figure is higher
		}
		
	}
	return maxHeight;
}

int Computer::LowColOfCurrPlacement(general* f)
{
	Point* body = f->getBodyPos();
	int currCol,lowCol;
	if (f->getSerial() != BOMB)
	{

		for (int i = 0; i < 4; i++)
		{
			currCol = body[i].getX();
			if (i == 0)
			{
				lowCol = currCol;
			}
			if (currCol < lowCol)
			{
				lowCol = currCol;
			}
		}
	}
	else
	{
		lowCol = f->getBodyPos()->getX();
	}
	return lowCol; // the col that appear in the most left side
}
int Computer::compareBetween2Placements(int maxHeight1, int maxHeight2, int numDeletedRows1, int numDeletedRows2,int* BestHeight,int* BestRow,int Col1,int Col2)
{
	if (maxHeight1 > maxHeight2)
	{
		*BestHeight = maxHeight1;
	}
	else if(maxHeight1 < maxHeight2)
	{
		*BestHeight = maxHeight2;
	}
	if (numDeletedRows1 > numDeletedRows2)
	{
		*BestRow = numDeletedRows1;
	}
	else if(numDeletedRows1 < numDeletedRows2)
	{
		*BestRow = numDeletedRows2;
	}
	if (*BestRow == numDeletedRows1 && *BestHeight == maxHeight1)
	{
		return Col1;
	}
	else if (*BestRow == numDeletedRows2 && *BestHeight == maxHeight2)
	{
		return Col2;
	}
	else if (*BestRow == numDeletedRows1 && *BestHeight != maxHeight1)
	{
		return Col1;
	}
	else if (*BestRow == numDeletedRows2 && *BestHeight != maxHeight2)
	{
		return Col2;
	}

}
void Computer::RandMove(general *f, int NumPlayer)
{
	int randRotate = rand() % SIZE;
	int randX = rand() % COLS;//0-11 5
	int x = 6;
	x = x + 1;
	if (NumPlayer == LEFT_PLAYER)
	{
		randX = 1 + randX;
	}
	else
	{
		randX = COLS + 2 + randX;
	}
	if (f->getSerial() != BOMB)
	{
		while (f->getRotateNum() != randRotate&& f->update(GameBoard, f->getSerial(), CLOCKWISE, 1))
		{
			//f->update(GameBoard, f->getSerial(), CLOCKWISE, 1);
			f->print(GameBoard);

			Sleep(100);
		}
	}
	while (LowColOfCurrPlacement(f) <randX)
	{
		f->update(GameBoard, f->getSerial(), RIGHT, 1);
		f->print(GameBoard);
		Sleep(100);
	}
	while (LowColOfCurrPlacement(f) >randX)
	{
		f->update(GameBoard, f->getSerial(), LEFT, 1);
		f->print(GameBoard);
		Sleep(100);
	}
}

