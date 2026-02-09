#include "Game_Scene.h"
#include "ClearScene/Clear_Scene.h"
#include <Novice.h>
#include <algorithm>
#include <memory>

Game_Scene::Game_Scene() {
  player_ = std::make_unique<Player>();

  inputHandler_ = std::make_unique<InputHandler>();
  inputHandler_->AssignMoveLeftCommand();
  inputHandler_->AssignMoveRightCommand();

  commands_ = nullptr;
}

std::unique_ptr<SceneBase> Game_Scene::Update(char *keys, char *preKeys) {

  commands_ = inputHandler_->HandleInput();

  if (this->commands_) {
    commands_->Exec(*player_);
  }

  if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
    return std::make_unique<Clear_Scene>();
  }
  return nullptr;
}

void Game_Scene::Render() const {
  Novice::ScreenPrintf(20, 20, "Game Scene");
  Novice::ScreenPrintf(20, 40, "Press SPACE to Clear");
  Novice::ScreenPrintf(20, 60, "Press A to Move Left");
  Novice::ScreenPrintf(20, 80, "Press D to Move Right");

  player_->Render();
}
