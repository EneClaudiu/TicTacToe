#include "ConsoleGameListener.h"

void ConsoleGameListener::OnWin(std::string playerName)
{
	std::cout << playerName << " won! Congratulations!\n";
}

void ConsoleGameListener::OnDraw()
{
	std::cout << "Draw!\n";
}

void ConsoleGameListener::OnMove(std::string playerName)
{
	std::cout << playerName << "'s move!\n";

}

void ConsoleGameListener::OnPositionInvalid()
{
	std::cout << "Position is not valid! Try another!";
}