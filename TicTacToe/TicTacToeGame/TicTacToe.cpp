#include "TicTacToe.h"
#include <iostream>

ITicTacToePtr ITicTacToe::Produce(ETicTacToeGameType type)
{
	if (type == ETicTacToeGameType::Impl1)
		return std::make_shared<TicTacToe>();
	return {};
}

TicTacToe::TicTacToe(std::string player1, std::string player2) {
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			m_board[i][j] = None;
	m_turnNumber = 0;

	m_player1 = player1;
	m_player2 = player2;

	currentOption = O;
}

bool TicTacToe::IsWin(std::pair<int,int> position) const {
	int newMoveRow = position.first;
	int newMoveColumn = position.second;
	for (int i = 0; i < boardSize; i++) {
		if (m_board[newMoveRow][i] != currentOption)
			break;
		if (i == boardSize - 1)
			return true;
	}
	for (int i = 0; i < boardSize; i++)
	{
		if (m_board[i][newMoveColumn] != currentOption)
			break;
		if (i == boardSize - 1)
			return true;
	}
	if (newMoveColumn == newMoveRow)
		for (int i = 0; i < boardSize; i++)
		{
			if (m_board[i][i] != currentOption)
				break;
			if (i == boardSize - 1)
				return true;
		}
	if (newMoveColumn + newMoveRow == boardSize - 1)
		for (int i = 0; i < boardSize; i++)
		{
			if (m_board[i][boardSize - 1 - i] != currentOption)
				break;
			if (i == boardSize - 1)
				return true;
		}
	return false;
}

void TicTacToe::NextMove(std::pair<int,int> position) {
	if (m_board[position.first][position.second] == None) {
		m_board[position.first][position.second] = currentOption;
		m_turnNumber++;
		if (currentOption == X)
			currentOption = O;
		else
			currentOption = X;
	}
}