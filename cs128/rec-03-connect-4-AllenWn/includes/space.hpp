#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>

class Space {
public:
  char GetSpace() const;

  void SetSpace(char icon);

private:
  char space_ = ' ';  // can only be X, O, or a space
};

#endif