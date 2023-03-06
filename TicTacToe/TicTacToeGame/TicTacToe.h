#pragma once

#include "ITicTacToe.h"

#include <string>

class TicTacToe2 : public ITicTacToe
{
public:
	bool IsWin() const override;
	bool IsPositionEmpty(std::pair<int, int>position) const override;
	void NextMove(std::pair<int, int> position) override;
};

class TicTacToe : public ITicTacToe
{
public:
	// ITicTacToe implementation
	bool IsWin() const override;
	void NextMove(std::pair<int, int> position) override;
	bool IsPositionEmpty(std::pair<int, int>position) const override;

	// IOtherInterface implementation
	//.....

	// other methods
	// ......

private:
	const int boardSize = 3;
	char m_board[3][3];
	int m_turnNumber;
	std::string m_player1;
	std::string m_player2;
};

