#include "player.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "opponent.h"

void Player::Draw(graphics::Image &screen) {
  graphics::Image jett;
  jett.Load("jett.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = jett.GetColor(i, j);
      screen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void Player::Move(const graphics::Image &screen) {}

void PlayerProjectile::Draw(graphics::Image &screen) {
  graphics::Image proj;
  proj.Load("JettKnives.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = proj.GetColor(i, j);
      screen.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void PlayerProjectile::Move(const graphics::Image &screen) {
  SetY(GetY() - 1);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}
