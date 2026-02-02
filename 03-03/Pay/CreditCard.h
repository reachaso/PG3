#pragma once
#include "PaymentMethod.h"

// =========================================================
// クレカ：限度額の範囲なら支払える（簡易モデル）
// =========================================================
class CreditCard : public PaymentMethod {
public:
  CreditCard(int limitYen, int usedYen = 0)
      : limitYen_(limitYen), usedYen_(usedYen) {}

  bool Pay(int amountYen) override {
    if (usedYen_ + amountYen > limitYen_) {
      std::cout << "  限度額オーバー！ 利用=" << usedYen_
                << "円 / 限度=" << limitYen_ << "円\n";
      return false;
    }
    usedYen_ += amountYen;
    std::cout << "  クレカで支払い。利用=" << usedYen_
              << "円 / 限度=" << limitYen_ << "円\n";
    return true;
  }

  std::string Name() const override { return "クレジットカード"; }

private:
  int limitYen_;
  int usedYen_;
};
