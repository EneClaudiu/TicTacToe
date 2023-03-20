#pragma once

#include <utility>
#include <memory>
#include <string>

#include "ITicTacToeListener.h"

enum class ETicTacToeGameType
{
	Impl1,
};

using ITicTacToePtr = std::shared_ptr<class ITicTacToe>;

class ITicTacToe
{
private:
public:
	static ITicTacToePtr Produce(ETicTacToeGameType type);

	virtual bool IsWin(std::pair<int,int> position) = 0;
	virtual void NextMove(std::pair<int, int> position) = 0;
	virtual void PrintBoard() = 0;
	virtual void SetPlayerNames(std::string player1, std::string player2) = 0;
	virtual std::string GetCurrentPlayer() const = 0;
	virtual bool IsDraw(std::pair<int, int> position) = 0;
	virtual void ResetGame() = 0;

	virtual void AddTicTacToeListener(ITicTacToeListener* listener) = 0;
	virtual void RemoveTicTacToeListener(ITicTacToeListener* listener) = 0;

	virtual ~ITicTacToe() = default;
};
