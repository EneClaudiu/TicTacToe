#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utility>

#include "TicTacToe.h"

using namespace testing;

class MockTicTacToeGame : public ITicTacToe
{
public:
	MOCK_METHOD(bool, IsWin, ((std::pair<int, int> position)), (override));
	MOCK_METHOD(void, NextMove, ((std::pair<int, int> position)), (override));

};


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
