#pragma once

#include "ITicTacToe.h"

#include <string>

class TicTacToe : public ITicTacToe
{
private:
	enum Options{
		X,
		O,
		None
	};
	Options currentOption;
	const int boardSize = 3;
	Options m_board[3][3];
	int m_turnNumber;
	std::string m_player1;
	std::string m_player2;
public:
	// ITicTacToe implementation
	TicTacToe(std::string player1 = "Player1", std::string player2 = "Player2");

	bool IsWin(std::pair<int,int> position) const override;
	void NextMove(std::pair<int, int> position) override;


	// IOtherInterface implementation
	//.....

	// other methods
	// ......

};

