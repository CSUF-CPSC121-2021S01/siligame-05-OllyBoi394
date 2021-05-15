#include "game_element.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void GameElement::Draw(graphics::Image& rect) {
  graphics::Color black(0, 0, 0);
  rect.DrawRectangle(x_, y_, 5, 5, black);
}

bool GameElement::IntersectsWith(GameElement* juego) {
  return !(GetX() > juego->GetX() + juego->GetWidth() ||
           juego->GetX() > x_ + GetWidth() ||
           GetY() > juego->GetY() + juego->GetHeight() ||
           juego->GetY() > y_ + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& ob) {
  return !((GetY() >= 0) && (ob.GetHeight() > GetY() + GetHeight()) &&
           (GetX() >= 0) && (ob.GetWidth() > GetX() + GetWidth()));
}

void GameElement::PadPoints(std::vector<int>& points, int pad_x, int pad_y) {
  for (int i = 0; i < points.size(); i++) {
    if (i % 2 == 0) {
      points[i] += pad_x;
    } else {
      points[i] += pad_y;
    }
  }
}
