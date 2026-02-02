#include "Game.h"
#include <Novice.h>

Game::Game() : currentScene_(kTitle) {}

void Game::Shutdown() {}

void Game::Run(char* keys, char* preKeys) {
  if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
    if (currentScene_ == kTitle) {
      currentScene_ = kGame;
    } else if (currentScene_ == kGame) {
      currentScene_ = kClear;
    } else {
      currentScene_ = kTitle;
    }
  }

  if (currentScene_ == kTitle) {
    titleScene_.Update(keys, preKeys);
  } else if (currentScene_ == kGame) {
    gameScene_.Update(keys, preKeys);
  } else {
    clearScene_.Update(keys, preKeys);
  }
}

void Game::Render() {
  if (currentScene_ == kTitle) {
    titleScene_.Render();
  } else if (currentScene_ == kGame) {
    gameScene_.Render();
  } else {
    clearScene_.Render();
  }
}
