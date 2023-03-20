#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utility>

#include "TicTacToe.h"

using namespace testing;

class TicTacToeMock : public ITicTacToe
{
public:
	MOCK_METHOD(bool, IsWin, ((std::pair<int, int> position)), (override));
	MOCK_METHOD(void, NextMove, ((std::pair<int, int> position)), (override));
	MOCK_METHOD(void, PrintBoard, (), (override));
	MOCK_METHOD(void, SetPlayerNames, ((std::string player1), std::string player2)), (override);
	MOCK_METHOD(std::string, GetCurrentPlayer, (), (const, override));
	MOCK_METHOD(bool, IsDraw, ((std::pair<int, int> position)), (override));
	MOCK_METHOD(void, ResetGame, (), (override));
};

class MockTicTacToeListener : public ITicTacToeListener
{
public:
	MOCK_METHOD(void, OnWin, ((std::string)), (override));
	MOCK_METHOD(void, OnMove, ((std::string)), (override));
	MOCK_METHOD(void, OnDraw, (), (override));
	MOCK_METHOD(void, OnPositionInvalid, (), (override));
};

TEST(TicTacToeTests, IsPositionInvalid)
{
	TicTacToe game;
	MockTicTacToeListener listener;
	game.AddTicTacToeListener(&listener);

	EXPECT_CALL(listener, OnMove("Player1")).Times(2);
	EXPECT_CALL(listener, OnPositionInvalid());

	game.NextMove({ 0, 0 });
	game.NextMove({ 0,0 });


}

TEST(TicTacToeTests, IsWinTestsTrue)
{
	TicTacToe game;
	MockTicTacToeListener listener;
	game.AddTicTacToeListener(&listener);

	game.SetPlayerNames("Player1", "Player2");

	EXPECT_CALL(listener, OnMove("Player1")).Times(3);
	EXPECT_CALL(listener, OnMove("Player2")).Times(2);
	EXPECT_CALL(listener, OnWin("Player1"));

	game.NextMove({ 0,0 });
	game.IsWin({ 0,0 });
	game.NextMove({ 0,1 });
	game.IsWin({ 0,1 });
	game.NextMove({ 1,1 });
	game.IsWin({ 1,1 });
	game.NextMove({ 2,1 });
	game.IsWin({ 2,1 });
	game.NextMove({ 2,2 });
	game.IsWin({ 2,2 });

	Mock::VerifyAndClearExpectations(&listener);
	game.RemoveTicTacToeListener(&listener);

}

TEST(TicTacToeTests, IsGameDraw)
{
	TicTacToe game;
	MockTicTacToeListener listener;
	game.AddTicTacToeListener(&listener);

	game.SetPlayerNames("Player1", "Player2");

	EXPECT_CALL(listener, OnMove("Player1")).Times(5);
	EXPECT_CALL(listener, OnMove("Player2")).Times(4);
	EXPECT_CALL(listener, OnDraw());

	game.NextMove(std::make_pair(0, 0)); //Player1
	game.IsWin({ 0,0 });
	game.NextMove(std::make_pair(0, 1)); //Player2
	game.IsWin({ 0,1 });
	game.NextMove(std::make_pair(0, 2)); //Player1
	game.IsWin({ 0,2 });
	game.NextMove(std::make_pair(1, 0)); //Player2
	game.IsWin({ 1,0 });
	game.NextMove(std::make_pair(1, 2)); //Player1
	game.IsWin({ 1,2 });
	game.NextMove(std::make_pair(2, 0)); //Player2
	game.IsWin({ 2,0 });
	game.NextMove(std::make_pair(1, 1)); //Player1
	game.IsWin({ 1,1 });
	game.NextMove(std::make_pair(2, 2)); //Player2
	game.IsWin({ 2,2 });
	game.NextMove(std::make_pair(2, 1)); //Player1
	game.IsDraw({2,2});

	Mock::VerifyAndClearExpectations(&listener);
	game.RemoveTicTacToeListener(&listener);

}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
