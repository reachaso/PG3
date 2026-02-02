#pragma once

class IShape {

public:
  // 面積を求める
  virtual void Size() = 0;
  // 結果を表示する
  virtual void Draw() = 0;
};
