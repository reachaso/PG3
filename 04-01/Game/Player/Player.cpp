#include "Player.h"
#include <Novice.h>
#include <algorithm>

Player::Player() {
  position_ = {640.0f, 640.0f};
  speed_ = 6.0f;
}

Player::~Player() {}

void Player::Move(char* keys) {
  if (keys[DIK_LEFT] || keys[DIK_A]) {
    position_.x -= speed_;
  }
  if (keys[DIK_RIGHT] || keys[DIK_D]) {
    position_.x += speed_;
  }

  if (position_.x < halfSize_.x) {
    position_.x = halfSize_.x;
  }
  if (position_.x > 1280.0f - halfSize_.x) {
    position_.x = 1280.0f - halfSize_.x;
  }
}

void Player::Attack(char* keys, char* preKeys) {
  if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
    Vector2 bulletPos{position_.x, position_.y - halfSize_.y - 5.0f};
    bullets_.emplace_back(bulletPos);
  }
}

void Player::Update(char* keys, char* preKeys) {
  Move(keys);
  Attack(keys, preKeys);

  for (Bullet& bullet : bullets_) {
    bullet.Move();
  }

  bullets_.erase(
      std::remove_if(bullets_.begin(), bullets_.end(),
                     [](const Bullet& bullet) { return !bullet.IsActive(); }),
      bullets_.end());
}

void Player::Render() const {
  for (const Bullet& bullet : bullets_) {
    bullet.Render();
  }

  Novice::DrawBox(static_cast<int>(position_.x - halfSize_.x),
                  static_cast<int>(position_.y - halfSize_.y),
                  static_cast<int>(halfSize_.x * 2),
                  static_cast<int>(halfSize_.y * 2), 0.0f, WHITE,
                  kFillModeSolid);
}

Vector2 Player::GetPosition() const { return position_; }

Vector2 Player::GetHalfSize() const { return halfSize_; }

std::vector<Bullet>& Player::GetBullets() { return bullets_; }

const std::vector<Bullet>& Player::GetBullets() const { return bullets_; }
