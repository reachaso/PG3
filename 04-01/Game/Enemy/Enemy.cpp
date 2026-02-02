#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(Vector2 pos) {
  position_ = pos;
  isAlive_ = true;
}

void Enemy::Render() const {
  if (!isAlive_) {
    return;
  }
  Novice::DrawBox(static_cast<int>(position_.x - halfSize_.x),
                  static_cast<int>(position_.y - halfSize_.y),
                  static_cast<int>(halfSize_.x * 2),
                  static_cast<int>(halfSize_.y * 2), 0.0f, RED,
                  kFillModeSolid);
}

bool Enemy::IsAlive() const { return isAlive_; }

void Enemy::SetAlive(bool isAlive) { isAlive_ = isAlive; }

Vector2 Enemy::GetPosition() const { return position_; }

Vector2 Enemy::GetHalfSize() const { return halfSize_; }
