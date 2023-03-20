#include "ITicTacToe.h"
#include "ConsoleGameListener.h"

#include <iostream>

int main() {
    std::string player1, player2;
    std::cout << "Enter Player 1 name: "; std::cin >> player1;
    std::cout << "Enter Player 2 name: "; std::cin >> player2;

    ITicTacToePtr game = ITicTacToe::Produce(ETicTacToeGameType::Impl1);

    ConsoleGameListener listener;
    game->AddTicTacToeListener(&listener);

    game->SetPlayerNames(player1, player2);
    game->PrintBoard();

    int row, column;

    std::cin >> row >> column;

    game->NextMove({ row,column });
    game->PrintBoard();

    while (!game->IsWin({ row,column }))
    {
        std::cin >> row >> column;
        game->NextMove({ row,column });
        game->PrintBoard();
        if (game->IsDraw({ row,column }))
        {
            break;
        }
    }

    game->RemoveTicTacToeListener(&listener);
    
    return 0;
}