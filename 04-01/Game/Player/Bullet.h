#pragma once
#include "struct.h"

class Bullet {

public:
  Bullet(Vector2 pos);
  ~Bullet();
  void Move();
  void Render() const;

  bool IsActive() const;
  void SetActive(bool isActive);
  Vector2 GetPosition() const;
  Vector2 GetHalfSize() const;

private:
  Vector2 position_;
  float speed_;
  bool isActive_;
  Vector2 bulletHalfSize_{5.0f, 5.0f};
};
