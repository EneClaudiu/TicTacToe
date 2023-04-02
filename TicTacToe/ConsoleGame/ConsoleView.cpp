
#include "ConsoleView.h"

void ConsoleView::PrintBoard(ITicTacToePtr game)
{
	std::cout << DisplayOption(game->GetBoard()[0][0]) << " | " << DisplayOption(game->GetBoard()[0][1]) << " | " << DisplayOption(game->GetBoard()[0][2]) << "\n";
	std::cout << "--+---+--\n";
	std::cout << DisplayOption(game->GetBoard()[1][0]) << " | " << DisplayOption(game->GetBoard()[1][1]) << " | " << DisplayOption(game->GetBoard()[1][2]) << "\n";
	std::cout << "--+---+--\n";
	std::cout << DisplayOption(game->GetBoard()[2][0]) << " | " << DisplayOption(game->GetBoard()[2][1]) << " | " << DisplayOption(game->GetBoard()[2][2]) << "\n";
}

char ConsoleView::DisplayOption(ITicTacToe::Options o)
{
	if (o == ITicTacToe::Options::X)
		return 'X';
	if (o == ITicTacToe::Options::O)
		return 'O';
	return ' ';
}
