#include "board.hpp"
#include <stdexcept>
#include <iostream>


Board::Board(int row, int col, Space defult_value) {
  if (row < 4 || col < 4) {
    throw std::invalid_argument("row and col can not smaller than 4");
  }
  board_ = std::vector(row, std::vector(col, defult_value));
}


void Board::PlaceDisk(unsigned int col, char icon) {
  for (int i = static_cast<int>(board_.size() - 1); i >= 0; i--) {
    if (board_.at(i).at(col).GetSpace() == ' ') {
      board_.at(i).at(col).SetSpace(icon);
      return;
    }
  }
}

char Board::CheckDiagonalWinner() {
  for (size_t i > 0, i < )
}

std::ostream& operator<<(std::ostream& os, const Board& b_in) {
  for (unsigned int row = 0; row < b_in.board_.size(); row++) {
    for (unsigned int col = 0; col < b_in.board_[row].size(); col++) {
      os << "|" << b_in.board_[row][col].GetSpace();
    }
    os << "|" << std::endl;
  }
  return os;
}
