#pragma once
#include "struct.h"

class Player {
public:
  Player();
  ~Player();
  void Update(char *keys, char *preKeys);
  void Render();

  void MoveRight();
  void MoveLeft();

private:
  Vector2 position_{};
  Vector2 size_{};
  float speed_;
};
