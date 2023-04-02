#pragma once
#include "ITicTacToe.h"
#include <iostream>
class ConsoleView
{
public:
	static void PrintBoard(ITicTacToePtr game);

private:
	static char DisplayOption(ITicTacToe::Options o);
};

