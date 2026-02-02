#pragma once
#include "PaymentMethod.h"

// =========================================================
// 交通系IC：残高があれば支払える（簡易モデル）
// =========================================================
class IC : public PaymentMethod {
public:
  explicit IC(int balanceYen) : balanceYen_(balanceYen) {}

  bool Pay(int amountYen) override {
    if (balanceYen_ < amountYen) {
      std::cout << "  IC残高不足！ 残高=" << balanceYen_ << "円\n";
      return false;
    }
    balanceYen_ -= amountYen;
    std::cout << "  ICタッチで支払い。残高=" << balanceYen_ << "円\n";
    return true;
  }

  std::string Name() const override { return "交通系IC"; }

private:
  int balanceYen_;
};
