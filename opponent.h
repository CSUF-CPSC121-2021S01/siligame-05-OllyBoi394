#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class Opponent : public GameElement {
 private:
  bool going_right_ = true;

 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& screen) override;
  void Move(const graphics::Image& screen) override;
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image& screen) override;
  void Move(const graphics::Image& screen) override;
};

#endif
