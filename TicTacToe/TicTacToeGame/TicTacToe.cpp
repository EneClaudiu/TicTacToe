#include "TicTacToe.h"

ITicTacToePtr ITicTacToe::Produce(ETicTacToeGameType type)
{
	if (type == ETicTacToeGameType::Impl1)
		return std::make_shared<TicTacToe>();
	if (type == ETicTacToeGameType::Impl2)
		return std::make_shared<TicTacToe2>();
	return {};
}
