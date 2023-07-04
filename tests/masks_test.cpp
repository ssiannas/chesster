#include <Masks.hpp>
#include <bit>
#include <gtest/gtest.h>

using namespace chesster;

TEST(mask_tests, rankMaskTest) {
  for (size_t i = 0; i < 8; i++) {
    EXPECT_EQ(RANK_MASKS[i], (unsigned long long)0xFF << (i * 8));
    EXPECT_EQ(std::popcount(RANK_MASKS[i]), 8);
  }
}

TEST(mask_tests, fileMaskTest) {
  for (size_t i = 0; i < 8; i++) {
    EXPECT_EQ(FILE_MASKS[i], 0x0101010101010101ULL << i);
    EXPECT_EQ(std::popcount(FILE_MASKS[i]), 8);
  }
}

TEST(mask_tests, whiteInitTest) {
  auto whiteBB = W_KING_INIT | W_QUEEN_INIT | W_BISHOPS_INIT | W_KNIGHTS_INIT |
                 W_ROOKS_INIT | W_PAWNS_INIT;
  EXPECT_EQ(whiteBB, 0x000000000000FFFFULL);
  EXPECT_EQ(std::popcount(whiteBB), 16);
  EXPECT_EQ(whiteBB & ~(RANK_MASKS[0] | RANK_MASKS[1]), 0);
}

TEST(mask_tests, blackInitTest) {
  auto blackBB = B_KING_INIT | B_QUEEN_INIT | B_BISHOPS_INIT | B_KNIGHTS_INIT |
                 B_ROOKS_INIT | B_PAWNS_INIT;

  EXPECT_EQ(blackBB, 0xFFFF000000000000ULL);
  EXPECT_EQ(std::popcount(blackBB), 16);
  EXPECT_EQ(blackBB & ~(RANK_MASKS[6] | RANK_MASKS[7]), 0);
}
