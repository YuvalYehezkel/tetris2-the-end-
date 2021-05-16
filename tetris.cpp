#include "tetris.h"
#include "Computer.h"


void tetris::ChooseGame() // צריך להוסיף אופציה של תפריט כאן ולא רק במשחקים עצמים
{
	char key_char = 0;
	TheGame* game = nullptr;
	Computer c1 ;
	Computer c2;

	Menu m;
	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			if (game == nullptr && key_char == INSTRUCTIO_KEYS)
			{
				game->getMenuInstructions();
			}
			if (key_char == STARTHvsH)
			{
				game = new HumanVsHuman();

			}
			else if (key_char == STARTHvsC)
			{
				gotoxy(30, 9);
				cout << "Hi! please enter the level of the computer:" << endl;
				c1.ChooseComputerLevel();
				game = new HumanVsComputer();

			}
			else if (key_char == STARTCvsC)
			{
				gotoxy(30, 9);
				cout << "please enter the level of the left computer player:"<<endl;
				c1.ChooseComputerLevel();
				gotoxy(30, 9);
				cout << "please enter the level of the right computer player:"<<endl;
				c2.ChooseComputerLevel();

				game = new ComputerVsComputer();

			}
			game->RunGame(c1.getLevel(),c2.getLevel());
			delete game;

		}
	}
}



