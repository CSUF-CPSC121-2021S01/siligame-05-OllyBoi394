#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 private:
  graphics::Image gscreen;
  std::vector<Opponent> op_;
  std::vector<OpponentProjectile> opp_;
  std::vector<PlayerProjectile> pp_;
  Player pl_;

 public:
  Game() : Game(800, 600) {}
  Game(int width, int height) : gscreen(width, height) {}

  graphics::Image& GetGameScreen() { return gscreen; }
  std::vector<Opponent>& GetOpponents() { return op_; }
  std::vector<OpponentProjectile>& GetOpponentProjectiles() { return opp_; }
  std::vector<PlayerProjectile>& GetPlayerProjectiles() { return pp_; }
  Player& GetPlayer() { return pl_; }

  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();

  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;

  void MoveGameElements();
  void FilterIntersections();

  void Init();
  void UpdateScreen();
  void Start() { gscreen.ShowUntilClosed(); }
};

#endif
