#include "Player.h"
#include <Novice.h>

Player::Player() {
  position_ = {100.0f, 100.0f};
  size_ = {50.0f, 50.0f};
  speed_ = 5.0f;
}

Player::~Player() {}

void Player::Update(char *keys, char *preKeys) {
  (void)preKeys;
  (void)keys;
}

void Player::Render() {
  Novice::DrawBox(static_cast<int>(position_.x), static_cast<int>(position_.y),
                  static_cast<int>(size_.x), static_cast<int>(size_.y), 0.0f,
                  WHITE, kFillModeSolid);
}

void Player::MoveRight() { this->position_.x += speed_; }

void Player::MoveLeft() { this->position_.x -= speed_; }
