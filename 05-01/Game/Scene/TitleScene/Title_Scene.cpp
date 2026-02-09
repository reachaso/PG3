#include "Title_Scene.h"
#include "GameScene/Game_Scene.h"
#include <Novice.h>
#include <memory>

std::unique_ptr<SceneBase> Title_Scene::Update(char* keys, char* preKeys) {
  if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
    return std::make_unique<Game_Scene>();
  }
  return nullptr;
}

void Title_Scene::Render() const {
  Novice::ScreenPrintf(20, 20, "Title Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Start");
}
