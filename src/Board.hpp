#ifndef BOARD_H
#define BOARD_H
#include "ChessTypes.hpp"
#include "Masks.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>

namespace chesster {

class Board {
public:
  Board() { initBoard(); }

public:
private:
  BitBoard _pieceBB[12];
  BitBoard _whiteBB{0};
  BitBoard _blackBB{0};
  static constexpr BitBoard _emptyBB{0};
  static constexpr BitBoard _occupiedBB{std::numeric_limits<BitBoard>::max()};

public:
  BitBoard getPieceSet(PieceType pt) const { return _pieceBB[utils::val(pt)]; }
  BitBoard getPawns(Team t) const {
    return _pieceBB[utils::val(PieceType::WHITE_PAWN) + utils::val(t)];
  }
  void printBoard() {
    std::cout << "  A B C D E F G H" << std::endl;
    for (int i = 0; i < 8; ++i) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; ++j) {
        BitBoard bb = 1ULL << (i * 8 + j);
        bool empty = true;
        for (int k = 0; k < 12; ++k) {
          if (_pieceBB[k] & bb) {
            empty = false;
            auto pieceASCII{utils::pieceToAscii(static_cast<PieceType>(k))};
            std::cout << pieceASCII << " ";
            break;
          }
        }
        if (empty)
          std::cout << "- ";
      }
      std::cout << std::endl;
    }
  }

private:
  void initBoard() {
    _pieceBB[utils::val(PieceType::WHITE_KING)] = W_KING_INIT;
    _pieceBB[utils::val(PieceType::WHITE_QUEEN)] = W_QUEEN_INIT;
    _pieceBB[utils::val(PieceType::WHITE_KNIGHT)] = W_KNIGHTS_INIT;
    _pieceBB[utils::val(PieceType::WHITE_ROOK)] = W_ROOKS_INIT;
    _pieceBB[utils::val(PieceType::WHITE_BISHOP)] = W_BISHOPS_INIT;
    _pieceBB[utils::val(PieceType::WHITE_PAWN)] = W_PAWNS_INIT;

    _pieceBB[utils::val(PieceType::BLACK_KING)] = B_KING_INIT;
    _pieceBB[utils::val(PieceType::BLACK_QUEEN)] = B_QUEEN_INIT;
    _pieceBB[utils::val(PieceType::BLACK_KNIGHT)] = B_KNIGHTS_INIT;
    _pieceBB[utils::val(PieceType::BLACK_ROOK)] = B_ROOKS_INIT;
    _pieceBB[utils::val(PieceType::BLACK_BISHOP)] = B_BISHOPS_INIT;
    _pieceBB[utils::val(PieceType::BLACK_PAWN)] = B_PAWNS_INIT;

    _whiteBB = _pieceBB[utils::val(PieceType::WHITE_KING)] |
               _pieceBB[utils::val(PieceType::WHITE_QUEEN)] |
               _pieceBB[utils::val(PieceType::WHITE_KNIGHT)] |
               _pieceBB[utils::val(PieceType::WHITE_ROOK)] |
               _pieceBB[utils::val(PieceType::WHITE_BISHOP)] |
               _pieceBB[utils::val(PieceType::WHITE_PAWN)];

    _blackBB = _pieceBB[utils::val(PieceType::BLACK_KING)] |
               _pieceBB[utils::val(PieceType::BLACK_QUEEN)] |
               _pieceBB[utils::val(PieceType::BLACK_KNIGHT)] |
               _pieceBB[utils::val(PieceType::BLACK_ROOK)] |
               _pieceBB[utils::val(PieceType::BLACK_BISHOP)] |
               _pieceBB[utils::val(PieceType::BLACK_PAWN)];
  }
};

} // namespace chesster
#endif // BOARD_H
