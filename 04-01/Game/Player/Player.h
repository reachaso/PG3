#pragma once
#include "struct.h"

class Player {
public:
  Player();
  ~Player();

  void Move();
  void Attack();

  void Update();
  void Render();

private:
  Vector2 position_;
};
