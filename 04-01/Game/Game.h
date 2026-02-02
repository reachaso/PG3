#pragma once
#include "Scene/ClearScene/ClearScene.h"
#include "Scene/GameScene/GameScene.h"
#include "Scene/TitleScene/TitleScene.h"

class Game {
public:
  Game();
  void Shutdown();
  void Run(char* keys, char* preKeys);
  void Render();

private:
  enum SceneType {
    kTitle,
    kGame,
    kClear
  };

  SceneType currentScene_;
  TitleScene titleScene_;
  GameScene gameScene_;
  ClearScene clearScene_;
};
