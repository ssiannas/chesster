#ifndef MOVE_HPP
#define MOVE_HPP

#include <ChessTypes.hpp>
#include <Utils.hpp>

namespace chesster {
enum class MoveFlags : unsigned short int {
  QUIET_MOVE = 0,
  DOUBLE_PAWN_PUSH,
  KING_CASTLE,
  QUEEN_CASTLE,
  CAPTURE,
  EN_PASSANT_CAP = 5,
  KNIGHT_PROMO = 8,
  BISHOP_PROMO,
  ROOK_PROMO,
  QUEEN_PROMO,
  KNIGHT_PROMO_CAP,
  BISHOP_PROMO_CAP,
  ROOK_PROMO_CAP,
  QUEEN_PROMO_CAP,
};

class Move {
private:
  unsigned short int move_{0};

public:
  Move(Squares from, Squares to, MoveFlags flags) {
    move_ = ((utils::val(flags) & 0xf) << 12) |
            ((utils::val(from) & 0x3f) << 6) | (utils::val(to) & 0x3f);
  }

  Square from() const { return static_cast<Square>((move_ >> 6) & 0x3f); }

  Square to() const { return static_cast<Square>(move_ & 0x3f); }

  MoveFlags flags() const {
    return static_cast<MoveFlags>((move_ >> 12) & 0xf);
  }

  bool is_capture() const {
    return (utils::val(flags()) & utils::val(MoveFlags::CAPTURE)) ==
           utils::val(MoveFlags::CAPTURE);
  }

  // Knight promo is the first promo flag, so we can just check this
  bool is_promotion() const {
    return (utils::val(flags()) & utils::val(MoveFlags::KNIGHT_PROMO)) ==
           utils::val(MoveFlags::KNIGHT_PROMO);
  }

  bool is_en_passant() const {
    return utils::val(flags()) == utils::val(MoveFlags::EN_PASSANT_CAP);
  }
};
} // namespace chesster

#endif // MOVE_HPP
