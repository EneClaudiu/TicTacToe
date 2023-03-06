#pragma once

#include <utility>
#include <memory>

enum class ETicTacToeGameType
{
	Impl1,
	Impl2
};

using ITicTacToePtr = std::shared_ptr<class ITicTacToe>;

class ITicTacToe
{
public:
	static ITicTacToePtr Produce(ETicTacToeGameType type);

	virtual bool IsWin() const = 0;
	virtual bool IsPositionEmpty(std::pair<int, int>position) const = 0;
	virtual void NextMove(std::pair<int, int> position) = 0;

	virtual ~ITicTacToe() = default;
};
