#include <Move.hpp>
#include <gtest/gtest.h>

using namespace chesster;

TEST(MoveTest, MoveEncodingTest) {
  Move m{Squares::E2, Squares::E4, MoveFlags::DOUBLE_PAWN_PUSH};
  EXPECT_EQ(m.from(), Squares::E2);
  EXPECT_EQ(m.to(), Squares::E4);
  EXPECT_EQ(m.flags(), MoveFlags::DOUBLE_PAWN_PUSH);
}
