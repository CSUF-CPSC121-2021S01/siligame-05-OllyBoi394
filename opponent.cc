#include "opponent.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void Opponent::Draw(graphics::Image& screen) {
  graphics::Image enemy;
  enemy.Load("ReynaLeer.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = enemy.GetColor(i, j);
      screen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void Opponent::Move(graphics::Image& screen) {
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}

void OpponentProjectile::Draw(graphics::Image& screen) {
  graphics::Image enproj;
  enproj.Load("ReynaDevour.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = enproj.GetColor(i, j);
      screen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void OpponentProjectile::Move(graphics::Image& screen) {
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}
