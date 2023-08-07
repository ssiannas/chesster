#include <Board.hpp>
#include <Utils.hpp>
#include <bit>
#include <gtest/gtest.h>

using namespace chesster;

TEST(UtilsTests, TestPopLSB) {
  BitBoard board = 0x0000000000000001ULL;
  EXPECT_EQ(utils::popLSB(board), 1);
  EXPECT_EQ(board, 0);
}

TEST(UtilsTests, TestGetLSB) {
  BitBoard board = 0x0000000000000001ULL;
  EXPECT_EQ(utils::getLSB(board), 1);
  EXPECT_EQ(board, 1);
}

TEST(UtilsTests, TestGetLSBSquare) {
  BitBoard board = 0x0000000000000001ULL;
  Square s = utils::getLSBSquare(board);
  EXPECT_EQ(s, utils::val(Squares::H1));
}
