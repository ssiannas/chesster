#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

namespace chesster {
typedef unsigned long long BitBoard;
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
