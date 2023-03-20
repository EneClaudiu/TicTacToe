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

class TicTacToeListenerMock : public ITicTacToeListener
{
public:
	MOCK_METHOD(void, OnWin, ((std::string)), (override));
	MOCK_METHOD(void, OnMove, ((std::string)), (override));
	MOCK_METHOD(void, OnDraw, (), (override));
};

TEST(TicTacToeTests, IsWinTestsTrue)
{

	auto gameMock = std::make_shared<TicTacToeMock>();

	EXPECT_CALL(*gameMock, IsWin(std::pair<int, int>(2, 2)))
		.WillOnce(Return(true));

	gameMock->NextMove({ 0,0 }); 
	gameMock->NextMove({ 1,0 }); 
	gameMock->NextMove({ 1,1 }); 
	gameMock->NextMove({ 0,2 }); 
	gameMock->NextMove({ 2,2 }); 

	ASSERT_TRUE(gameMock->IsWin({ 2,2 }));

}

TEST(TicTacToeTests, IsWinTestsFalse)
{

	auto gameMock = std::make_shared<TicTacToeMock>();

	EXPECT_CALL(*gameMock, IsWin(std::pair<int, int>(2, 1)))
		.WillOnce(Return(false));

	gameMock->NextMove({ 0,0 });
	gameMock->NextMove({ 1,0 });
	gameMock->NextMove({ 1,1 });
	gameMock->NextMove({ 0,2 });
	gameMock->NextMove({ 1,2 });
	gameMock->NextMove({ 2,2 });
	gameMock->NextMove({ 0,2 });
	gameMock->NextMove({ 0,1 });
	gameMock->NextMove({ 2,1 });

	ASSERT_FALSE(gameMock->IsWin({ 2,1 }));
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
