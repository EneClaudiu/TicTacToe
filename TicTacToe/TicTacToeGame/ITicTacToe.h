#pragma once

#include <utility>
#include <memory>

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

	virtual bool IsWin(std::pair<int,int> position) const = 0;
	virtual void NextMove(std::pair<int, int> position) = 0;

	virtual ~ITicTacToe() = default;
};
