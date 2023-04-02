#pragma once

#include "ITicTacToe.h"

#include <string>
#include <vector>

class TicTacToe : public ITicTacToe
{
private:

	Options currentOption;
	const int boardSize = 3;
	Options m_board[3][3];
	int m_turnNumber;
	std::string m_player1;
	std::string m_player2;
	std::string* m_currentPlayer;

	//char DisplayOption(Options o);
	void ChangePlayer();
public:

	TicTacToe();

	bool IsWin(std::pair<int,int> position) override;
	void NextMove(std::pair<int, int> position) override;
	void PrintBoard() override;
	void SetPlayerNames(std::string player1, std::string player2) override;
	std::string GetCurrentPlayer() const override;
	bool IsDraw(std::pair<int, int> position) override;
	void ResetGame() override;
	ITicTacToe::Options** GetBoard() override;
	void AddTicTacToeListener(ITicTacToeListener* listener) override;
	void RemoveTicTacToeListener(ITicTacToeListener* listener) override;

private:
	std::vector<ITicTacToeListener*> listeners;
	
};

