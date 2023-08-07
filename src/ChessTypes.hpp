#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

namespace chesster {
typedef unsigned long long BitBoard;

using Square = char;

// clang-format off
enum class Squares : Square {
    H1, G1, F1, E1, D1, C1, B1, A1,
    H2, G2, F2, E2, D2, C2, B2, A2,
    H3, G3, F3, E3, D3, C3, B3, A3,
    H4, G4, F4, E4, D4, C4, B4, A4,
    H5, G5, F5, E5, D5, C5, B5, A5,
    H6, G6, F6, E6, D6, C6, B6, A6,
    H7, G7, F7, E7, D7, C7, B7, A7,
    H8, G8, F8, E8, D8, C8, B8, A8,
    NUM_SQUARES
};
// clang-format on

constexpr bool operator==(const Squares &lhs, const Squares &rhs) {
  return static_cast<Square>(lhs) == static_cast<Square>(rhs);
}

constexpr bool operator==(const Square &lhs, const Squares &rhs) {
  return lhs == static_cast<Square>(rhs);
}

constexpr bool operator==(const Squares &lhs, const Square &rhs) {
  return static_cast<Square>(lhs) == rhs;
}

enum Team { WHITE, BLACK };

enum PieceType {
  WHITE_KING,
  BLACK_KING,
  WHITE_QUEEN,
  BLACK_QUEEN,
  WHITE_KNIGHT,
  BLACK_KNIGHT,
  WHITE_ROOK,
  BLACK_ROOK,
  WHITE_BISHOP,
  BLACK_BISHOP,
  WHITE_PAWN,
  BLACK_PAWN,
  NONE,
};
} // namespace chesster

#endif
