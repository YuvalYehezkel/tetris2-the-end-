#pragma once
#include "Board.h"
enum MenuKeys { STARTHvsH = '1', STARTHvsC = '2', STARTCvsC = '3', PAUSE1 = '4', INSTRUCTIO_KEYS = '8', EXIT = '9' };

class Menu
{
public:
	Menu() { printMenu(); };
	void StartNewGame(char key_char, int& y1, int& y2, Board& GameBoard);
	void ShowInstructions()const;
	void ContinuePausedGame(char key_char, Board& GameBoard);
	void ExitGame()const;
	void printMenu()const;
}; 
