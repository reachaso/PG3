#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Update(char* keys, char* preKeys) {
  keys;
  preKeys;
}

void ClearScene::Render() const {
  Novice::ScreenPrintf(20, 20, "Clear Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Title");
}
