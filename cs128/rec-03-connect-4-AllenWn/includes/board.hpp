#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>

#include "space.hpp"

class Board {
public:

  Board(int row, int col, Space defult_value);

  void PlaceDisk(unsigned int col, char icon);

  char CheckDiagonalWinner();

  friend std::ostream& operator<<(std::ostream& os, const Board& b_in);

private:
  std::vector<std::vector<Space>> board_;
};

std::ostream& operator<<(std::ostream& os, const Board& b_in);

#endif
