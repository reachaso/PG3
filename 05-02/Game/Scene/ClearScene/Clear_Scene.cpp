#include "Clear_Scene.h"
#include "TitleScene/Title_Scene.h"
#include <Novice.h>
#include <memory>

std::unique_ptr<SceneBase> Clear_Scene::Update(char* keys, char* preKeys) {
  if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
    return std::make_unique<Title_Scene>();
  }
  return nullptr;
}

void Clear_Scene::Render() const {
  Novice::ScreenPrintf(20, 20, "Clear Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Title");
}
