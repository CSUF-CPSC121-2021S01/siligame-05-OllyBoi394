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

void Opponent::Move(const graphics::Image& screen) {
  if (going_right_ && GetX() + GetWidth() >= screen.GetWidth()) {
    going_right_ = false;
  } else if (!going_right_ && GetX() <= 0) {
    going_right_ = true;
  }
  int offset = going_right_ ? 1 : -1;

  SetX(GetX() + offset * 5);
  SetY(GetY() + 2);

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

void OpponentProjectile::Move(const graphics::Image& screen) {
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}

std::unique_ptr<class OpponentProjectile> Opponent::LaunchProjectile() {
  if (count % 30 == 0) {
    count++;
    return std::make_unique<OpponentProjectile>(GetX() + 25, GetY());
  }
  count++;
  return nullptr;
}
