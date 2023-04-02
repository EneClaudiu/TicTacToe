#include "TicTacToe.h"
#include <iostream>

ITicTacToePtr ITicTacToe::Produce(ETicTacToeGameType type)
{
	if (type == ETicTacToeGameType::Impl1)
		return std::make_shared<TicTacToe>();
	return {};
}

void TicTacToe::AddTicTacToeListener(ITicTacToeListener* listener)
{
	listeners.push_back(listener);
}

void TicTacToe::RemoveTicTacToeListener(ITicTacToeListener* listener)
{
	for (auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if (*it == listener)
		{
			listeners.erase(it);
			break;
		}
	}
}

TicTacToe::TicTacToe() {
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			m_board[i][j] = None;
	m_turnNumber = 0;

	m_player1 = "Player1";
	m_player2 = "Player2";

	currentOption = O;
	m_currentPlayer = &m_player1;
}

bool TicTacToe::IsWin(std::pair<int,int> position) {
	int newMoveRow = position.first;
	int newMoveColumn = position.second;

	for (int i = 0; i < boardSize; i++) {
		if (m_board[newMoveRow][i] != currentOption)
			break;
		if (i == boardSize - 1)
		{
			return true;
		}
	}
	for (int i = 0; i < boardSize; i++)
	{
		if (m_board[i][newMoveColumn] != currentOption)
			break;
		if (i == boardSize - 1) {
			
			return true;
		}
	}
	if (newMoveColumn == newMoveRow)
		for (int i = 0; i < boardSize; i++)
		{
			if (m_board[i][i] != currentOption)
				break;
			if (i == boardSize - 1) {
				
				return true;
			}
		}
	if (newMoveColumn + newMoveRow == boardSize - 1)
		for (int i = 0; i < boardSize; i++)
		{
			if (m_board[i][boardSize - 1 - i] != currentOption)
				break;
			if (i == boardSize - 1) {
				
				return true;
			}
		}
	
	return false;
}

void TicTacToe::ChangePlayer() {
	if (currentOption == X)
	{
		currentOption = O;
		m_currentPlayer = &m_player1;
	}
	else
	{
		currentOption = X;
		m_currentPlayer = &m_player2;
	}
}

void TicTacToe::NextMove(std::pair<int,int> position) {
	if (m_board[position.first][position.second] == None) {
		m_board[position.first][position.second] = currentOption;
		m_turnNumber++;

		for (ITicTacToeListener* listener : listeners)
			listener->OnMove(*m_currentPlayer);

		if (IsWin(position)) {
			for (ITicTacToeListener* listener : listeners)
				listener->OnWin(*m_currentPlayer);

			return;
		}
		else if (IsDraw(position)) {
			for (ITicTacToeListener* listener : listeners)
				listener->OnDraw();

			return;
		}

		ChangePlayer();
	}
	else
	{
		for (ITicTacToeListener* listener : listeners)
			listener->OnPositionInvalid();
	}
	

	


}
void TicTacToe::SetPlayerNames(std::string player1, std::string player2) {
	this->m_player1 = player1;
	this->m_player2 = player2;
}

//char TicTacToe::DisplayOption(Options o) {
//	if (o == X)
//		return 'X';
//	if (o == O)
//		return 'O';
//	return ' ';
//}

void TicTacToe::PrintBoard() {
	/*std::cout << this->DisplayOption(this->m_board[0][0]) << " | " << this->DisplayOption(this->m_board[0][1]) << " | " << this->DisplayOption(this->m_board[0][2]) << "\n";
	std::cout << "--+---+--\n";
	std::cout << this->DisplayOption(this->m_board[1][0]) << " | " << this->DisplayOption(this->m_board[1][1]) << " | " << this->DisplayOption(this->m_board[1][2]) << "\n";
	std::cout << "--+---+--\n";
	std::cout << this->DisplayOption(this->m_board[2][0]) << " | " << this->DisplayOption(this->m_board[2][1]) << " | " << this->DisplayOption(this->m_board[2][2]) << "\n";*/
}

std::string TicTacToe::GetCurrentPlayer() const{
	return *this->m_currentPlayer;
}
bool TicTacToe::IsDraw(std::pair<int, int> position) {
	if (m_turnNumber == boardSize * boardSize && !this->IsWin(position))
	{
		return true;
	}
	return false;
}

void TicTacToe::ResetGame() {
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			m_board[i][j] = None;
	m_turnNumber = 0;

	m_currentPlayer = &m_player1;
	currentOption = O;
}

ITicTacToe::Options** TicTacToe::GetBoard()
{
	Options** board = new Options * [boardSize];
	for (int i = 0; i < boardSize; i++) {
		board[i] = m_board[i];
	}
	return board;
}
