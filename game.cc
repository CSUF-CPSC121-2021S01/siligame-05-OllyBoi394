#include "game.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void Game::Init() {
  pl_.SetX(400);
  pl_.SetY(400);
  CreateOpponents();
  CreateOpponentProjectiles();
  CreatePlayerProjectiles();
  gscreen.AddMouseEventListener(*this);
  gscreen.AddAnimationEventListener(*this);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 5; i++) {
    Opponent op(100 * i, 20);
    op_.push_back(op);
  }
}

void Game::CreateOpponentProjectiles() {
  for (int i = 0; i < 5; i++) {
    OpponentProjectile opp(100 * i, 100);
    opp_.push_back(opp);
  }
}

void Game::CreatePlayerProjectiles() {
  for (int i = 0; i < 5; i++) {
    PlayerProjectile pp(100 * i, 450);
    pp_.push_back(pp);
  }
}

void Game::MoveGameElements() {
  for (int i = 0; i < pp_.size(); i++) {
    if (pp_[i].GetIsActive()) {
      pp_[i].Move(gscreen);
    }
  }
  for (int i = 0; i < op_.size(); i++) {
    if (op_[i].GetIsActive()) {
      op_[i].Move(gscreen);
    }
  }
  for (int i = 0; i < opp_.size(); i++) {
    if (opp_[i].GetIsActive()) {
      opp_[i].Move(gscreen);
    }
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < op_.size(); i++) {
    if (op_[i].GetIsActive() && pl_.GetIsActive() &&
        pl_.IntersectsWith(&op_[i])) {
      // op_.IntersectsWith(op_[i]);
      op_[i].SetIsActive(false);
      pl_.SetIsActive(false);
    } else {
      for (int j = 0; j < pp_.size(); j++) {
        if (op_[i].GetIsActive() && pp_[j].GetIsActive() &&
            pp_[j].IntersectsWith(&op_[i])) {
          op_[i].SetIsActive(false);
          pp_[j].SetIsActive(false);
        }
      }
    }
  }
  for (int i = 0; i < opp_.size(); i++) {
    if (opp_[i].GetIsActive() && pl_.GetIsActive() &&
        pl_.IntersectsWith(&opp_[i])) {
      opp_[i].SetIsActive(false);
      pl_.SetIsActive(false);
    }
  }
}

void Game::UpdateScreen() {
  if (pl_.GetIsActive()) {
    pl_.Draw(gscreen);
  }
  for (int i = 0; i < op_.size(); i++) {
    if (op_[i].GetIsActive()) {
      op_[i].Draw(gscreen);
    }
  }
  for (int i = 0; i < opp_.size(); i++) {
    if (opp_[i].GetIsActive()) {
      opp_[i].Draw(gscreen);
    }
  }
  for (int i = 0; i < pp_.size(); i++) {
    if (pp_[i].GetIsActive()) {
      pp_[i].Draw(gscreen);
    }
  }
}

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (event.GetMouseAction() == graphics::MouseAction::kMoved ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    int new_x = event.GetX() - pl_.GetWidth() / 2;
    int new_y = event.GetY() - pl_.GetHeight() / 2;
    int old_x = pl_.GetX();
    int old_y = pl_.GetY();

    pl_.SetX(new_x);
    pl_.SetY(new_y);
    if (pl_.IsOutOfBounds(gscreen)) {
      pl_.SetX(old_x);
      pl_.SetY(old_y);
    }
  }
}

void Game::OnAnimationStep() {
  MoveGameElements();
  FilterIntersections();
  UpdateScreen();
  gscreen.Flush();
}
