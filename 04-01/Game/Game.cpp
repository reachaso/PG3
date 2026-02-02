#include "Game.h"
#include "TitleScene/Title_Scene.h"
#include <Novice.h>
#include <memory>

Game::Game() : currentScene_(std::make_unique<Title_Scene>()) {}

void Game::Shutdown() {}

void Game::Run(char* keys, char* preKeys) {
  if (!currentScene_) {
    return;
  }
  std::unique_ptr<SceneBase> nextScene = currentScene_->Update(keys, preKeys);
  if (nextScene) {
    currentScene_ = std::move(nextScene);
  }
}

void Game::Render() {
  if (currentScene_) {
    currentScene_->Render();
  }
}
