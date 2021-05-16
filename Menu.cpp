#include "Menu.h"
#include <iostream>
#include "gotoxy.h"
#include <conio.h>
#include "Figure.h"
#include "TheGame.h"

using namespace std;

void Menu::ShowInstructions()const
{
	gotoxy(0, 27);
	std::cout << endl << "Goal: You have to make full horizontal lines with the different shaped blocks that fall into the game area.Full lines will then disappear and Increases the chance of winning the game" << endl;
	std::cout << "The player whose board is filled first loses, the other player wins" << endl;
	std::cout << "Controls:" << endl << "Player 1(The left player):" << endl << "'a' or 'A' key : move block to the left" << endl << "'d' or 'D' key : move block to the right" << endl << "'s' or 'S' key : rotate block clockwise" << endl << "'w' or 'W' key : rotate block counterclockwise" << endl << "'x' or 'X' key : move block down" << endl;
	std::cout << "Player 2(The right player):" << endl << "'j' or 'J' key : move block to the left" << endl << "'l' or 'L' key : move block to the right" << endl << "'k' or 'K' key : rotate block clockwise" << endl << "'i' or 'I' key : rotate block counterclockwise" << endl << "'m' or 'M' key : move block down" << endl;
}

void Menu::ContinuePausedGame(char key_char, Board& GameBoard)
{
	system("cls");
	gotoxy(13, 10);
	cout << "for continue press (4)" << endl;

	while (1) {

		// check the state of every key
		if (_kbhit())
		{
			key_char = _getch();
			if (key_char == MenuKeys::PAUSE1)
			{
				system("cls");
				GameBoard.PrintBoard();
				break;
			}

		}
	}
}
void Menu::StartNewGame(char key_char, int& y1, int& y2, Board& GameBoard)
{
	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			if (key_char == STARTHvsH || key_char == STARTHvsC || key_char == STARTCvsC)
			{
				GameBoard.initBoard();
				y1 = Y1;
				y2 = Y2;
				break;
			}
		}
	}
}
void Menu::ExitGame()const
{
	system("cls");
	exit(0);
}
void Menu::printMenu()const
{
	gotoxy(0, ROWS + 3);
	cout << "Please select one of the options:" << endl;
	cout << "(1) Start a new game - Human vs Human" << endl;
	cout << "(2) Start a new game - Human vs Computer" << endl;
	cout << "(3) Start a new game - Computer vs Computer" << endl;
	cout << "(4) Continue a paused game" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;
}