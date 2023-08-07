#ifndef UTILS_H
#define UTILS_H
#include "ChessTypes.hpp"
#include <bit>
#include <string>
#include <type_traits>

namespace chesster {
namespace utils {

template <typename E>
concept EnumType = std::is_enum_v<E>;
template <EnumType T> constexpr auto val(T value) {
  return static_cast<std::underlying_type_t<T>>(value);
}

constexpr void setBit(BitBoard &board, unsigned int pos) {
  board |= (1ULL << pos);
}

constexpr unsigned int getBit(BitBoard board, unsigned int file,
                              unsigned int rank) {
  return (board >> (rank * 8 + file)) & 1;
}

constexpr BitBoard bbFlipVertical(const BitBoard &board) {
  return __builtin_bswap64(board);
}

constexpr BitBoard bbFlipHorizontal(const BitBoard &board) {
  return ((board & 0x00000000000000FFULL) << 56) |
         ((board & 0x000000000000FF00ULL) << 40) |
         ((board & 0x0000000000FF0000ULL) << 24) |
         ((board & 0x00000000FF000000ULL) << 8) |
         ((board & 0x000000FF00000000ULL) >> 8) |
         ((board & 0x0000FF0000000000ULL) >> 24) |
         ((board & 0x00FF000000000000ULL) >> 40) |
         ((board & 0xFF00000000000000ULL) >> 56);
}

constexpr wchar_t pieceUnicodeChars[]{L'♔', L'♚', L'♕', L'♛', L'♘', L'♞',
                                      L'♖', L'♜', L'♗', L'♝', L'♙', L'\u265F'};

constexpr wchar_t pieceToUnicode(PieceType piece) {
  return pieceUnicodeChars[val(piece)];
}

constexpr char pieceASCII[]{'K', 'k', 'Q', 'q', 'N', 'n',
                            'R', 'r', 'B', 'b', 'P', 'p'};

constexpr char pieceToAscii(PieceType piece) { return pieceASCII[val(piece)]; }

constexpr std::string_view pieceChars{"KkQqNnRrBbPp"};

constexpr PieceType getPieceType(char c) {
  size_t pos = pieceChars.find(c);
  if (pos != std::string::npos) {
    return static_cast<PieceType>(pos);
  }
  return PieceType::NONE;
}

inline Team parseTeam(std::string team) {
  if (team == "w")
    return Team::WHITE;
  if (team == "b")
    return Team::BLACK;
  return Team::WHITE;
}

constexpr BitBoard popLSB(BitBoard &board) {
  BitBoard lsb = board & -board;
  board &= board - 1;
  return lsb;
}

constexpr BitBoard getLSB(const BitBoard board) { return board & -board; }

constexpr Square getLSBSquare(const BitBoard board) {
  return static_cast<Square>(std::countr_zero(board));
}
} // namespace utils
} // namespace chesster

#endif // UTILS_H
