#pragma once
#include "ITicTacToeListener.h"
#include <iostream>
class ConsoleGameListener : public ITicTacToeListener
{
	 void OnWin(std::string playerName) override;
	 void OnMove(std::string playerName) override;
	 void OnDraw() override;
	 void OnPositionInvalid() override;
};

