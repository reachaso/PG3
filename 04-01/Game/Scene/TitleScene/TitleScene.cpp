#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Update(char* keys, char* preKeys) {
  keys;
  preKeys;
}

void TitleScene::Render() const {
  Novice::ScreenPrintf(20, 20, "Title Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Start");
}
