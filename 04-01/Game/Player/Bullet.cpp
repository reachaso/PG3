#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(Vector2 pos) {
  position_ = pos;
  speed_ = 10.0f;
  isActive_ = true;
}

Bullet::~Bullet() {}

void Bullet::Move() {
  if (!isActive_) {
    return;
  }
  position_.y -= speed_;
  if (position_.y + bulletHalfSize_.y < 0.0f) {
    isActive_ = false;
  }
}

void Bullet::Render() const {
  if (isActive_) {
    Novice::DrawBox(static_cast<int>(position_.x - bulletHalfSize_.x),
                    static_cast<int>(position_.y - bulletHalfSize_.y),
                    static_cast<int>(bulletHalfSize_.x * 2),
                    static_cast<int>(bulletHalfSize_.y * 2), 0.0f, WHITE,
                    kFillModeSolid);
  }
}

bool Bullet::IsActive() const { return isActive_; }

void Bullet::SetActive(bool isActive) { isActive_ = isActive; }

Vector2 Bullet::GetPosition() const { return position_; }

Vector2 Bullet::GetHalfSize() const { return bulletHalfSize_; }
