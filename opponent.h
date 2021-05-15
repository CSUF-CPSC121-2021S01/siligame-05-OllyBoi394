#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(const int& x, const int& y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& screen);
  void Move(graphics::Image& screen);
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(const int& x, const int& y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image& screen);
  void Move(graphics::Image& screen);
};

#endif
