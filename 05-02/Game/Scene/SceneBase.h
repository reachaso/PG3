#pragma once
#include <memory>

class SceneBase {
public:
  virtual ~SceneBase() = default;
  virtual std::unique_ptr<SceneBase> Update(char* keys, char* preKeys) = 0;
  virtual void Render() const = 0;
};
