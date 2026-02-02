#pragma once
#include "PaymentMethod.h"

// =========================================================
// 現金払い：手持ちが足りれば支払える
// =========================================================
class Cash : public PaymentMethod {
public:
  explicit Cash(int walletYen) : walletYen_(walletYen) {}

  bool Pay(int amountYen) override {
    if (walletYen_ < amountYen) {
      std::cout << "  現金が足りない！ 残高=" << walletYen_ << "円\n";
      return false;
    }
    walletYen_ -= amountYen;
    std::cout << "  現金で支払い。残高=" << walletYen_ << "円\n";
    return true;
  }

  std::string Name() const override { return "現金"; }

private:
  int walletYen_;
};
