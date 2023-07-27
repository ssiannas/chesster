#include <Board.hpp>
#include <iostream>

auto main() -> int {
  auto b = chesster::Board();
  b.positionFromFEN(
      "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
  std::cout << b;
}
