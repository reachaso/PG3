#pragma once
#include "struct.h"

class Enemy {
public:
  Enemy(Vector2 pos);

  void Render() const;
  bool IsAlive() const;
  void SetAlive(bool isAlive);
  Vector2 GetPosition() const;
  Vector2 GetHalfSize() const;

private:
  Vector2 position_;
  Vector2 halfSize_{20.0f, 20.0f};
  bool isAlive_;
};
