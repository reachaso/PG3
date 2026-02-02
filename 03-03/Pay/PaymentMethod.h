#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// =========================================================
// 支払い方法の共通インターフェース（= 基底クラス）
// 「支払う」という操作だけ共通に約束する
// =========================================================
class PaymentMethod {
public:
  virtual ~PaymentMethod() = default;

  // 派生クラスごとに処理が変わる
  virtual bool Pay(int amountYen) = 0;

  // 表示用（デバッグ/ログ）
  virtual std::string Name() const = 0;
};
