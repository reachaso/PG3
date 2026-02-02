#pragma once
#include <cstddef> // size_t
#include <iostream>

class Enemy {
public:
  Enemy();
  void Update();

private:
  // =========================
  // 状態（フェーズ）
  // =========================
  enum class Phase : std::size_t {
    Approach = 0, // 接近
    Shoot,        // 射撃
    Retreat,      // 離脱
    Count
  };

  // =========================
  // メンバ関数ポインタ型
  // =========================
  using StateFunc = void (Enemy::*)();

  // =========================
  // 状態ごとの処理
  // =========================
  void StateApproach();
  void StateShoot();
  void StateRetreat();

  // 状態切り替え（見通し良くする用）
  void ChangePhase(Phase next);

private:
  // 現在の状態
  Phase phase_;

  // それっぽく見せるための値（コンソール用の疑似パラメータ）
  int distance_;  // プレイヤーとの距離（近いほど小さい）
  int shotsLeft_; // 射撃の残り回数

  // =========================
  // 状態テーブル（資料の形）
  // =========================
  static StateFunc s_stateTable[static_cast<std::size_t>(Phase::Count)];
};
