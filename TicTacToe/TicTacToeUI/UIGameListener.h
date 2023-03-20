#pragma once
#include "ITicTacToeListener.h"
#include <string>
class UIGameListener : public ITicTacToeListener
{
	void OnWin(std::string playerName) override;
	void OnDraw() override;
	void OnMove(std::string playerName) override;
};

