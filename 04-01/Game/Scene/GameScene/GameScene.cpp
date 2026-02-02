#include "GameScene.h"
#include <Novice.h>

void GameScene::Update(char* keys, char* preKeys) {
  keys;
  preKeys;
}

void GameScene::Render() const {
  Novice::ScreenPrintf(20, 20, "Game Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Clear");
}
