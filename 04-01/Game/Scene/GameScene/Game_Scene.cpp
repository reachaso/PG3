#include "Game_Scene.h"
#include "ClearScene/Clear_Scene.h"
#include <Novice.h>
#include <algorithm>
#include <memory>

Game_Scene::Game_Scene() {
  const int enemyCount = 3;
  const float startX = 440.0f;
  const float y = 120.0f;
  const float spacing = 180.0f;

  enemies_.reserve(enemyCount);
  for (int i = 0; i < enemyCount; ++i) {
    Vector2 pos{startX + spacing * i, y};
    enemies_.emplace_back(pos);
  }
}

std::unique_ptr<SceneBase> Game_Scene::Update(char* keys, char* preKeys) {
  player_.Update(keys, preKeys);

  std::vector<Bullet>& bullets = player_.GetBullets();
  for (Bullet& bullet : bullets) {
    if (!bullet.IsActive()) {
      continue;
    }
    for (Enemy& enemy : enemies_) {
      if (!enemy.IsAlive()) {
        continue;
      }
      if (IsCollision(bullet.GetPosition(), bullet.GetHalfSize(),
                      enemy.GetPosition(), enemy.GetHalfSize())) {
        bullet.SetActive(false);
        enemy.SetAlive(false);
        break;
      }
    }
  }

  bool allDefeated = std::all_of(
      enemies_.begin(), enemies_.end(),
      [](const Enemy& enemy) { return !enemy.IsAlive(); });

  if (allDefeated) {
    isEnemyDefeated_ = true;
  }

  if (isEnemyDefeated_) {
    return std::make_unique<Clear_Scene>();
  }
  return nullptr;
}

void Game_Scene::Render() const {
  Novice::ScreenPrintf(20, 20, "Game Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Shot");
  for (const Enemy& enemy : enemies_) {
    enemy.Render();
  }
  player_.Render();
}

void Game_Scene::SetEnemyDefeated(bool isDefeated) {
  isEnemyDefeated_ = isDefeated;
}

bool Game_Scene::IsCollision(const Vector2& posA, const Vector2& halfA,
                             const Vector2& posB,
                             const Vector2& halfB) const {
  return (posA.x - halfA.x < posB.x + halfB.x &&
          posA.x + halfA.x > posB.x - halfB.x &&
          posA.y - halfA.y < posB.y + halfB.y &&
          posA.y + halfA.y > posB.y - halfB.y);
}
