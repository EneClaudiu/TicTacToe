#pragma once
#include <string>
class ITicTacToeListener
{
public:
	virtual void OnWin(std::string playerName) = 0;
	virtual void OnMove(std::string playerName) = 0;
	virtual void OnDraw() = 0;
	virtual void OnPositionInvalid() = 0;
};

