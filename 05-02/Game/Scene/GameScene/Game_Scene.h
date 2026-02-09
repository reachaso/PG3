#pragma once
#include "Command/Command.h"
#include "Input/InputHandler.h"
#include "Player.h"
#include "SceneBase.h"
#include <vector>

class Game_Scene : public SceneBase {
public:
  Game_Scene();
  std::unique_ptr<SceneBase> Update(char *keys, char *preKeys) override;
  void Render() const override;

private:
  // プレイヤー
  std::unique_ptr<Player> player_;

  // 入力ハンドラ
  std::unique_ptr <InputHandler> inputHandler_;

  // コマンド
  ICommand *commands_;
};
