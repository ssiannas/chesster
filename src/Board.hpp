#ifndef BOARD_H
#define BOARD_H
#include "ChessTypes.hpp"
#include "Masks.hpp"
#include "Utils.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

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
  static constexpr BitBoard _fullBB{std::numeric_limits<BitBoard>::max()};
  BitBoard _occupiedBB{0};
  Team _teamToMove{Team::WHITE};

public:
  BitBoard getPieceSetPieceType(PieceType pt) const { return _pieceBB[(pt)]; }
  BitBoard getPawns(Team t) const {
    return _pieceBB[PieceType::WHITE_PAWN + t];
  }

  Team getTeamToMove() {
    return _teamToMove;
  }

  BitBoard getOccupancy() const { return _occupiedBB; }
  void printBoard() {
    std::cout << "  A B C D E F G H" << std::endl;
    for (int i = 7; i >= 0; --i) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; ++j) {
        BitBoard bb = 1ULL << (i * 8 + j);
        bool empty = true;
        for (int k = 0; k < 12; ++k) {
          if (_pieceBB[k] & bb) {
            empty = false;
            char pieceASCII{utils::pieceToAscii(static_cast<PieceType>(k))};
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

  // Set up the piece bitboards to the given position
  // TODO: std::expected<void, errtype>
  void positionFromFEN(const std::string &fen) {
    std::istringstream iss(fen);
    std::string boardString, sideToMove, castlingRights, enPassantSquare,
        halfMoveClock, fullMoveNumber;
    if (!(iss >> boardString >> sideToMove >> castlingRights >>
          enPassantSquare >> halfMoveClock >> fullMoveNumber)) {
      return;
    }

    for (auto &piece : _pieceBB) {
      piece = 0;
    }

    int rank = 7, file = 0;
    for (char c : boardString) {
      if (c == '/') {
        --rank;
        file = 0;
      } else if (std::isdigit(c)) {
        file += c - '0';
      } else {
        PieceType pieceType{utils::getPieceType(c)};
        if (pieceType != PieceType::NONE) {
          int square = rank * 8 + file;
          _pieceBB[(pieceType)] |= (1ULL << square);
        }
        file++;
      }
    }

    _teamToMove = utils::parseTeam(sideToMove);

    updateBitBoards();
  }

private:
  void initBoard() {
    _pieceBB[PieceType::WHITE_KING] = W_KING_INIT;
    _pieceBB[PieceType::WHITE_QUEEN] = W_QUEEN_INIT;
    _pieceBB[PieceType::WHITE_KNIGHT] = W_KNIGHTS_INIT;
    _pieceBB[PieceType::WHITE_ROOK] = W_ROOKS_INIT;
    _pieceBB[PieceType::WHITE_BISHOP] = W_BISHOPS_INIT;
    _pieceBB[PieceType::WHITE_PAWN] = W_PAWNS_INIT;

    _pieceBB[PieceType::BLACK_KING] = B_KING_INIT;
    _pieceBB[PieceType::BLACK_QUEEN] = B_QUEEN_INIT;
    _pieceBB[PieceType::BLACK_KNIGHT] = B_KNIGHTS_INIT;
    _pieceBB[PieceType::BLACK_ROOK] = B_ROOKS_INIT;
    _pieceBB[PieceType::BLACK_BISHOP] = B_BISHOPS_INIT;
    _pieceBB[PieceType::BLACK_PAWN] = B_PAWNS_INIT;

    _whiteBB = _pieceBB[PieceType::WHITE_KING] |
               _pieceBB[PieceType::WHITE_QUEEN] |
               _pieceBB[PieceType::WHITE_KNIGHT] |
               _pieceBB[PieceType::WHITE_ROOK] |
               _pieceBB[PieceType::WHITE_BISHOP] |
               _pieceBB[PieceType::WHITE_PAWN];

    _blackBB = _pieceBB[PieceType::BLACK_KING] |
               _pieceBB[PieceType::BLACK_QUEEN] |
               _pieceBB[PieceType::BLACK_KNIGHT] |
               _pieceBB[PieceType::BLACK_ROOK] |
               _pieceBB[PieceType::BLACK_BISHOP] |
               _pieceBB[PieceType::BLACK_PAWN];
    updateBitBoards();
  }

  void updateBitBoards() {
    _whiteBB = _pieceBB[PieceType::WHITE_KING] |
               _pieceBB[PieceType::WHITE_QUEEN] |
               _pieceBB[PieceType::WHITE_KNIGHT] |
               _pieceBB[PieceType::WHITE_ROOK] |
               _pieceBB[PieceType::WHITE_BISHOP] |
               _pieceBB[PieceType::WHITE_PAWN];

    _blackBB = _pieceBB[PieceType::BLACK_KING] |
               _pieceBB[PieceType::BLACK_QUEEN] |
               _pieceBB[PieceType::BLACK_KNIGHT] |
               _pieceBB[PieceType::BLACK_ROOK] |
               _pieceBB[PieceType::BLACK_BISHOP] |
               _pieceBB[PieceType::BLACK_PAWN];

    _occupiedBB = _whiteBB | _blackBB;
  }
};

} // namespace chesster
#endif // BOARD_H
