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
	std::string* m_currentPlayer;

	char DisplayOption(Options o);
	void ChangePlayer();
public:
	// ITicTacToe implementation
	TicTacToe();

	bool IsWin(std::pair<int,int> position) override;
	void NextMove(std::pair<int, int> position) override;
	void PrintBoard() override;
	void SetPlayerNames(std::string player1, std::string player2) override;
	std::string GetCurrentPlayer() const override;
	bool IsDraw(std::pair<int, int> position) override;
	void ResetGame() override;

	// IOtherInterface implementation
	//.....

	// other methods
	// ......

};

