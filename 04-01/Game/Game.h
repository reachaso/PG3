#pragma once
#include "Scene/SceneBase.h"
#include <memory>

class Game {
public:
  Game();
  void Shutdown();
  void Run(char* keys, char* preKeys);
  void Render();

private:
  std::unique_ptr<SceneBase> currentScene_;
};
