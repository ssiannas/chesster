#ifndef BOARD_H
#define BOARD_H
#include <iostream>
namespace chesster {
typedef uint64_t BitBoard;

class Board {
public:
    Board() {
    }

public:
   enum Team {
    WHITE,
    BLACK
   };

   enum PieceType
   {
    whiteKing,
    blackKing,
    whiteQueen,
    blackQueen,
    whiteKnight,
    blackKnight,
    whiteRook,
    blackRook,
    whiteBishop,
    blackBishop,
    whitePawn,
    blackPawn,
   };

   BitBoard getPieceSet(PieceType pt) const {return _pieceBB[pt];}
   BitBoard getPawns(Team t) const {return _pieceBB[whitePawn + t];}

private:
   BitBoard _pieceBB[14];
   BitBoard _emptyBB;
   BitBoard _occupiedBB;
};

} // chesster
#endif //BOARD_H
