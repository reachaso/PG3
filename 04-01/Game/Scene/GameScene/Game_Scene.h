#pragma once
#include "Enemy.h"
#include "Player.h"
#include "SceneBase.h"
#include <vector>

class Game_Scene : public SceneBase {
public:
  Game_Scene();
  std::unique_ptr<SceneBase> Update(char* keys, char* preKeys) override;
  void Render() const override;
  void SetEnemyDefeated(bool isDefeated);

private:
  bool IsCollision(const Vector2& posA, const Vector2& halfA,
                   const Vector2& posB, const Vector2& halfB) const;

private:
  Player player_;
  std::vector<Enemy> enemies_;
  bool isEnemyDefeated_ = false;
};
