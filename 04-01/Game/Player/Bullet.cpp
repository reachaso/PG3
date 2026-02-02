#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(Vector2 pos) {
  position_ = pos;
  speed_ = 10.0f;
  isActive_ = true;
}

Bullet::~Bullet() {}

void Bullet::Move() {}

void Bullet::Render() {
  if (isActive_) {
    Novice::DrawBox(static_cast<int>(position_.x - bulletHalfSize_.x),
                    static_cast<int>(position_.y - bulletHalfSize_.y),
                    static_cast<int>(bulletHalfSize_.x * 2),
                    static_cast<int>(bulletHalfSize_.y * 2), 0.0f, WHITE,
                    kFillModeSolid);
  }
}
