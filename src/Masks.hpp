#ifndef MASKS_H
#define MASKS_H
#include "ChessTypes.hpp"
#include "Utils.hpp"

namespace chesster {
static constexpr BitBoard RANK_MASKS[]{
    0x00000000000000FFULL, 0x000000000000FF00ULL, 0x0000000000FF0000ULL,
    0x00000000FF000000ULL, 0x000000FF00000000ULL, 0x0000FF0000000000ULL,
    0x00FF000000000000ULL, 0xFF00000000000000ULL};
static constexpr BitBoard FILE_MASKS[]{
    0x0101010101010101ULL, 0x0202020202020202ULL, 0x0404040404040404ULL,
    0x0808080808080808ULL, 0x1010101010101010ULL, 0x2020202020202020ULL,
    0x4040404040404040ULL, 0x8080808080808080ULL};
// White pieces init
static constexpr BitBoard W_ROOKS_INIT = 0x0000000000000081ULL;
static constexpr BitBoard W_KNIGHTS_INIT = 0x0000000000000042ULL;
static constexpr BitBoard W_BISHOPS_INIT = 0x0000000000000024ULL;
static constexpr BitBoard W_QUEEN_INIT = 0x0000000000000008ULL;
static constexpr BitBoard W_KING_INIT = 0x0000000000000010ULL;
static constexpr BitBoard W_PAWNS_INIT = 0x000000000000FF00ULL;

// Black pieces init
static constexpr BitBoard B_ROOKS_INIT = utils::bbFlipVertical(W_ROOKS_INIT);
static constexpr BitBoard B_KNIGHTS_INIT =
    utils::bbFlipVertical(W_KNIGHTS_INIT);
static constexpr BitBoard B_BISHOPS_INIT =
    utils::bbFlipVertical(W_BISHOPS_INIT);
static constexpr BitBoard B_QUEEN_INIT = utils::bbFlipVertical(W_QUEEN_INIT);
static constexpr BitBoard B_KING_INIT = utils::bbFlipVertical(W_KING_INIT);
static constexpr BitBoard B_PAWNS_INIT = utils::bbFlipVertical(W_PAWNS_INIT);
} // namespace chesster
#endif // MASKS_H
