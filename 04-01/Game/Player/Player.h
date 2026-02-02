#pragma once
#include "Bullet.h"
#include "struct.h"
#include <vector>

class Player {
public:
  Player();
  ~Player();

  void Update(char* keys, char* preKeys);
  void Render() const;

  Vector2 GetPosition() const;
  Vector2 GetHalfSize() const;
  std::vector<Bullet>& GetBullets();
  const std::vector<Bullet>& GetBullets() const;

private:
  void Move(char* keys);
  void Attack(char* keys, char* preKeys);

private:
  Vector2 position_;
  Vector2 halfSize_{20.0f, 20.0f};
  float speed_;
  std::vector<Bullet> bullets_;
};
