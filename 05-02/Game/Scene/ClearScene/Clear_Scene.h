#pragma once
#include "SceneBase.h"

class Clear_Scene : public SceneBase {
public:
  std::unique_ptr<SceneBase> Update(char* keys, char* preKeys) override;
  void Render() const override;
};
