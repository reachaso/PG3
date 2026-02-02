#include "Enemy.h"

// =========================
// 状態テーブルの実体
// =========================
Enemy::StateFunc Enemy::s_stateTable[static_cast<std::size_t>(Phase::Count)] = {
    &Enemy::StateApproach, // 0: 接近
    &Enemy::StateShoot,    // 1: 射撃
    &Enemy::StateRetreat   // 2: 離脱
};

Enemy::Enemy() : phase_(Phase::Approach), distance_(4), shotsLeft_(0) {}

// =========================
// Update：状態テーブルから実行
// =========================
void Enemy::Update() {
  const std::size_t idx = static_cast<std::size_t>(phase_);
  (this->*s_stateTable[idx])();
}

void Enemy::ChangePhase(Phase next) { phase_ = next; }

// =========================
// 接近：距離を縮めて、近づいたら射撃へ
// =========================
void Enemy::StateApproach() {
  std::cout << "[接近] distance = " << distance_ << "\n";

  distance_ -= 2; // 接近するほど距離が減る

  if (distance_ <= 2) {
    shotsLeft_ = 1;            // 1回撃つことにする
    ChangePhase(Phase::Shoot); // 射撃へ
  }
}

// =========================
// 射撃：規定回数撃ったら離脱へ
// =========================
void Enemy::StateShoot() {
  std::cout << "[射撃] shotsLeft = " << shotsLeft_
            << " / distance = " << distance_ << "\n";

  --shotsLeft_;

  if (shotsLeft_ <= 0) {
    ChangePhase(Phase::Retreat); // 離脱へ
  }
}

// =========================
// 離脱：距離を離して、十分離れたら接近へ
// =========================
void Enemy::StateRetreat() {
  std::cout << "[離脱] distance = " << distance_ << "\n";

  distance_ += 2; // 離脱するほど距離が増える

  if (distance_ >= 4) {
    ChangePhase(Phase::Approach); // また接近へ（ループ）
  }
}
