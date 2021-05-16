#include "Figure.h"


void Figure::print(Board& board)
{

	for (int i=0;i<SIZE;i++)
	{
		if (board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety()))
		{
			board.turnToBusyPoint(FigureBody[i].getX(), FigureBody[i].gety());
		}

	}

}



void Figure::initFigureBySerialNum(int serial_num_of_figure, int x, int y,Board& board)
{

	switch (serial_num_of_figure) //1-8
	{
	case SHAPES::LINE:
	{

		for (int j = 0; j < SIZE; j++)
		{
			FigureBody[j].SetPoint(x + j, y, true, SIGN);

		}
		setSerial(LINE);
		

		break;

	}

	case SHAPES::L:
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x, y + 1, true, SIGN);
		FigureBody[2].SetPoint(x + 1, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x + 2, y + 1, true, SIGN);
		
		setSerial(L);
		
		break;
	}
	case SHAPES::RL://reversed L
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x, y + 1, true, SIGN);
		FigureBody[2].SetPoint(x - 1, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x - 2, y + 1, true, SIGN);

		setSerial(RL);
		

		break;
	}
	case SHAPES::SQUARE:
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x + 1, y, true, SIGN);
		FigureBody[2].SetPoint(x, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x + 1, y + 1, true, SIGN);

		setSerial(SQUARE);
		
		break;
	}
	case SHAPES::Z:
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x + 1, y, true, SIGN);
		FigureBody[2].SetPoint(x + 1, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x + 2, y + 1, true, SIGN);

		setSerial(Z);
		

		break;
	}


	case SHAPES::RZ://reversed Z
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x + 1, y, true, SIGN);
		FigureBody[2].SetPoint(x, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x - 1, y + 1, true, SIGN);

		setSerial(RZ);
		

		break;
	}

	case SHAPES::PLUS:
	{
		FigureBody[0].SetPoint(x, y, true, SIGN);
		FigureBody[1].SetPoint(x, y + 1, true, SIGN);
		FigureBody[2].SetPoint(x - 1, y + 1, true, SIGN);
		FigureBody[3].SetPoint(x + 1, y + 1, true, SIGN);

		setSerial(PLUS);
		

		break;
	}

	}

}

bool Figure::update(Board& board, int serialNum,int dir, int numFunc)
{
	switch (dir)
	{
	case direction::LEFT:
	{
		return updateFigureLeft(board, serialNum);
		break;
	}
	case direction::RIGHT:
	{
		return updateFigureRight(board, serialNum);
		break;
	}
	case direction::DOWN:
	{
		return updateFigureDrop(board, serialNum);
		break;
	}
	case direction::CLOCKWISE:
	{
		return updateFigureRotateClockWise(board, serialNum);
		break;
	}
	case direction::COUNTERCLOCKWISE:
	{
		return updateFigureRotateCounterClockWise(board, serialNum);
		break;
	}
	}
}

bool Figure::updateFigureDrop(Board& board, int serialNum)
{
	bool valid = true;

	switch (serialNum)
	{
	case SHAPES::LINE:
	{
		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 0; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			for (int i = 0; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		}
		break;

	}
	case SHAPES::L:
	{
		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}

		}
		break;

	}

	case SHAPES::RL:
	{
		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::SQUARE:
	{
		for (int i = 2; i < SIZE; i++)
		{
			if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
			{
				valid = false;
				break;
			}

		}
		break;
	}
	case SHAPES::Z:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}


			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)) || !(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}

			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}


		}
		break;
	}
	case SHAPES::RZ:
	{
		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) || !(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}

			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}


		}
		break;
	}
	case SHAPES::PLUS:
	{
		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX(), FigureBody[i].gety() + 1)))
				{
					valid = false;
					break;
				}

			}
			break;
		}
		case 1:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)) || !(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			if (!(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) ||
				!(board.isValidPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1)))
			{
				valid = false;
				break;
			}

			break;
		}
		case 3:
		{

			if (!(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) || !(board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1)))
			{
				valid = false;
				break;
			}
			break;
		}

		}
		break;
	}

	}
	if (valid == true)
	{
		// free the 
		for (int i = 0; i < SIZE; i++)
		{
			board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
		}
		FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 1, true, SIGN);
		FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1, true, SIGN);
		FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1, true, SIGN);
		FigureBody[3].SetPoint(FigureBody[3].getX(), FigureBody[3].gety() + 1, true, SIGN);
		
		

	}
	return valid;

}

bool Figure::updateFigureLeft(Board& board, int serialNum)
{
	bool valid = true;

	switch (serialNum)
	{
	case SHAPES::LINE:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			if (!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety())) ||
				!(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety()))
				|| (!board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))
				|| (!board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		case 2:
		{

			if (!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety())))
			{
				valid = false;
				break;
			}
			break;

		}
		case 3:
		{
			if (!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety())) ||
				!(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety()))
				|| (!board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))
				|| (!board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		}
		break;
	}
	case SHAPES::L:
	{

		switch (RotateNum)
		{
		case 0:
		{

			for (int i = 0; i < 2; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 1:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;

		}
		case 2:
		{
			if (!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety())) ||
				!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{

			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;

		}

		}

		break;
	}
	case SHAPES::RL:
	{
		switch (RotateNum)
		{

		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety()))) || (!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i <= 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}

			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}
		break;
	}
	case SHAPES::SQUARE:
	{

		if ((!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))))
		{
			valid = false;
			break;
		}


		break;
	}
	case SHAPES::Z:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{

			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}

		case 2:
		{

			if ((!(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE && i != 2; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		}

		break;
	}
	case SHAPES::RZ:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE && i != 2; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}

		}

		break;
	}
	case SHAPES::PLUS:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() - 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}
		break;
	}

	}
	if (valid == true)
	{
		// free the 
		for (int i = 0; i < SIZE; i++)
		{
			board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
		}
		FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety(), true, SIGN);
		FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety(), true, SIGN);
		FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety(), true, SIGN);
		FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety(), true, SIGN);

		

	}

	return valid;
}
bool Figure::updateFigureRight(Board& board, int serialNum)
{
	bool valid = true;

	switch (serialNum)
	{
	case SHAPES::LINE:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety())))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		}
		break;

	}
	case SHAPES::L:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if ((!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety()))))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}

		break;
	}
	case SHAPES::RL:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if ((!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety()))))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}

		break;
	}
	case SHAPES::SQUARE:
	{

		if ((!(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))))
		{
			valid = false;
			break;
		}


		break;
	}
	case SHAPES::Z:
	{

		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))) || (!(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE && i != 2; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[2].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if ((!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety()))))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}

		break;
	}
	case SHAPES::RZ:
	{

		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[2].gety()))) || (!(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE && i != 2; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if ((!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety()))))
				{
					valid = false;
					break;
				}
			}
			break;
		}


		}

		break;
	}
	case SHAPES::PLUS:
	{

		switch (RotateNum)
		{
		case 0:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < SIZE && i != 1; i++)
			{
				if (!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety())))
				{
					valid = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if ((!(board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety()))) || (!(board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[2].gety()))))
			{
				valid = false;
				break;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < SIZE; i++)
			{
				if ((!(board.isValidPoint(FigureBody[i].getX() + 1, FigureBody[i].gety()))))
				{
					valid = false;
					break;
				}
			}
			break;
		}

		}
		break;

	}


	}
	if (valid == true)
	{
		for (int i = 0; i < SIZE; i++)
		{
			board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
		}
		FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety(), true, SIGN);
		FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety(), true, SIGN);
		FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety(), true, SIGN);
		FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety(), true, SIGN);

		
	}
	return valid;

}

bool Figure::updateFigureRotateClockWise(Board& board, int serialNum)
{
	switch (serialNum)
	{
	case SHAPES::LINE:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety() - 1)) &&
				(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 2)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 2, true, SIGN);

				RotateNum = 1;
				
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[2].gety())) &&
				(board.isValidPoint(FigureBody[3].getX() - 2, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 2, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 2;
				
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety() + 1)) &&
				(board.isValidPoint(FigureBody[2].getX(), FigureBody[2].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 2)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 2, true, SIGN);

				RotateNum = 3;
			
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 2)) &&
				(board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[2].gety())) &&
				(board.isValidPoint(FigureBody[3].getX() + 2, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 2, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 0;
			
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::L:
	{

		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);
				RotateNum = 1;
				

			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1)))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);
				RotateNum = 2;
				

			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);
				RotateNum = 3;
				
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2)) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);
				RotateNum = 0;
				
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::RL:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 1;
			

			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1)))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);
				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);
				RotateNum = 3;

			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);
				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::SQUARE:
	{
		return false;
		break;
	}

	case SHAPES::Z:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety()) &&
				board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 1;

			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2) &&
				board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety()) &&
				board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2) &&
				board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);

				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;
		}
		}

		break;
	}
	case SHAPES::RZ:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 1) &&
				board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 2))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() + 2, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 1;
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() + 1) &&
				board.isValidPoint(FigureBody[1].getX() - 2, FigureBody[1].gety()))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 2, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);

				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 1) &&
				board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() - 2))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() - 2, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);

				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() - 1) &&
				board.isValidPoint(FigureBody[1].getX() + 2, FigureBody[1].gety()))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 2, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 0;
			}
			break;
		}
		}

		break;
	}
	case SHAPES::PLUS:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);

				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;
		}
		}

		break;
	}

	}
}
bool Figure::updateFigureRotateCounterClockWise(Board& board, int serialNum)
{
	switch (serialNum)
	{
	case SHAPES::LINE:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 2, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 2, FigureBody[3].gety() - 1, true, SIGN);

				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety() + 1)) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety())) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[0].gety() - 2)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 2, true, SIGN);

				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 2)) &&
				(board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 2, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 2, FigureBody[3].gety() + 1, true, SIGN);

				RotateNum = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety() - 1)) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety())) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 2)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 2, true, SIGN);


				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::L:
	{

		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1)))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2)) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 1;
				
			}

			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 2;
				
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}
	case SHAPES::RL:
	{
		switch (RotateNum)
		{
		case 0:
		{

			if ((board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 3;
				
			}
			else
			{
				return false;
			}

			break;
		}
		case 1:
		{
			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2)) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 2)))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 0;
				

			}
			else
			{
				return false;
			}
			break;
		}
		case 2:
		{
			if ((board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety())) &&
				(board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 1;
				
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if ((board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2)) &&
				(board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1)) &&
				(board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1)))
			{

				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 2;
				
			}
			else
			{
				return false;
			}
			break;
		}

		}
		break;
	}

	case SHAPES::Z:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2) &&
				board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() + 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 3;
				
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[0].getX() - 2, FigureBody[0].gety()) &&
				board.isValidPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);



				RotateNum = 0;
				
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2) &&
				board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX(), FigureBody[0].gety() - 2, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() - 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[0].getX() + 2, FigureBody[0].gety()) &&
				board.isValidPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 2, FigureBody[0].gety(), true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 1, FigureBody[1].gety() + 1, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 2;
			
			}
			else
			{
				return false;
			}
			break;
		}
		}

		break;
	}
	case SHAPES::RZ:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[1].getX() - 2, FigureBody[1].gety()) &&
				board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() - 2, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 3;
				
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() - 2) &&
				board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() - 2, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 0;
				
			}
			else
			{
				return false;
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[1].getX() + 2, FigureBody[1].gety() &&
				board.isValidPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1)))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX() + 2, FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 1;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[1].getX(), FigureBody[1].gety() + 2) &&
				board.isValidPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety() + 2, true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX(), FigureBody[2].gety(), true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;
		}
		}

		break;
	}
	case SHAPES::PLUS:
	{
		switch (RotateNum)
		{
		case 0:
		{
			if (board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() - 1, true, SIGN);


				RotateNum = 3;
			}
			else
			{
				return false;
			}
			break;
		}
		case 1:
		{
			if (board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[3].gety() + 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() - 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety() + 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() - 1, true, SIGN);



				RotateNum = 0;
			}
			else
			{
				return false;
			}
			break;

		}
		case 2:
		{
			if (board.isValidPoint(FigureBody[2].getX() - 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() - 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() - 1, FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() + 1, FigureBody[3].gety() + 1, true, SIGN);



				RotateNum = 1;
			}
			else
			{
				return false;
			}
			break;
		}
		case 3:
		{
			if (board.isValidPoint(FigureBody[2].getX() + 1, FigureBody[3].gety() - 1))
			{
				for (int i = 0; i < SIZE; i++)
				{
					board.turnToFreePoint(FigureBody[i].getX(), FigureBody[i].gety());
				}
				FigureBody[0].SetPoint(FigureBody[0].getX() + 1, FigureBody[0].gety() + 1, true, SIGN);
				FigureBody[1].SetPoint(FigureBody[1].getX(), FigureBody[1].gety(), true, SIGN);
				FigureBody[2].SetPoint(FigureBody[2].getX() + 1, FigureBody[2].gety() - 1, true, SIGN);
				FigureBody[3].SetPoint(FigureBody[3].getX() - 1, FigureBody[3].gety() + 1, true, SIGN);


				RotateNum = 2;
			}
			else
			{
				return false;
			}
			break;
		}
		}
		break;
	}
	}
}