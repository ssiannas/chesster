#include <Board.hpp>
#include <bit>
#include <gtest/gtest.h>
#include <ChessTypes.hpp>

using namespace chesster;

class BoardTests : public ::testing::Test {
public:
  const std::string testFEN{
      "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"};
  Board b;
};

TEST_F(BoardTests, initTest) {
  BitBoard occupiedBB = b.getOccupancy();
  EXPECT_EQ(occupiedBB, 0xFFFF00000000FFFFULL);
}

TEST_F(BoardTests, positionFromFENTest) {
  b.positionFromFEN(testFEN);
  b.printBoard();
  BitBoard occupiedBB = b.getOccupancy();
  EXPECT_EQ(occupiedBB, 0xFFFB00041020EFBFULL);
  EXPECT_EQ(std::popcount(occupiedBB), 32);
}

TEST_F(BoardTests, teamFromFENTest) {
  b.positionFromFEN(testFEN);
  EXPECT_EQ(b.getTeamToMove(), Team::BLACK);
}
