#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

namespace chesster {
typedef unsigned long long BitBoard;
enum class Team : int { WHITE, BLACK };

enum class PieceType : int {
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
};
} // namespace chesster

#endif
