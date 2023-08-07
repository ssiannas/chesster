#include <Board.hpp>
#include <ChessTypes.hpp>
#include <Move.hpp>
#include <bit>
#include <gtest/gtest.h>

using namespace chesster;

class BoardTests : public ::testing::Test {
public:
  const std::string testFEN{
      "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"};
  const std::string brokenFEN{"asasd - asd"};
  Board b;
};

TEST_F(BoardTests, initTest) {
  BitBoard occupiedBB = b.getOccupancy();
  EXPECT_EQ(occupiedBB, 0xFFFF00000000FFFFULL);
}

TEST_F(BoardTests, positionFromFENTest) {
  b.positionFromFEN(testFEN);
  std::cout << b;
  BitBoard occupiedBB = b.getOccupancy();
  EXPECT_EQ(occupiedBB, 0xFFFB00041020EFBFULL);
  EXPECT_EQ(std::popcount(occupiedBB), 32);
}

TEST_F(BoardTests, teamFromFENTest) {
  b.positionFromFEN(testFEN);
  EXPECT_EQ(b.getTeamToMove(), Team::BLACK);
}

TEST_F(BoardTests, failingFENTest) {
  EXPECT_THROW(b.positionFromFEN(brokenFEN), std::runtime_error);
}

TEST_F(BoardTests, movePieceTest) {
  Move m{Squares::E2, Squares::E4, MoveFlags::DOUBLE_PAWN_PUSH};
  b.performMove(m, PieceType::WHITE_PAWN);
  BitBoard occupiedBB = b.getOccupancy();
  // 1 1 1 1 1 1 1 1
  // 1 1 1 1 1 1 1 1
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0
  // 0 0 0 0 1 0 0 0
  // 0 0 0 0 0 0 0 0
  // 1 1 1 1 0 1 1 1
  // 1 1 1 1 1 1 1 1
  EXPECT_EQ(occupiedBB, 0xFFFF00000800F7FFULL);
}
