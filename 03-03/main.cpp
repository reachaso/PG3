#include "Pay/Cash.h"
#include "Pay/CreditCard.h"
#include "Pay/IC.h"
#include "Pay/PaymentMethod.h"
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

// =========================================================
// お店側：支払い方法の種類を知らない（PaymentMethodとして扱う）
// これがポリモーフィズムの「同じ呼び出しで挙動が変わる」部分
// =========================================================
bool Checkout(PaymentMethod &method, int totalYen) {
  std::cout << "[会計] 合計 " << totalYen << "円 / 方法=" << method.Name()
            << "\n";
  bool ok = method.Pay(totalYen);
  std::cout << (ok ? "  => 支払い成功\n" : "  => 支払い失敗\n");
  return ok;
}

int main() {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  // インスタンス生成（支払い方法を差し替える
  // 現金 : 手持ち1000円
  Cash cash(1000);
  // クレジットカード : 限度額5000円 , 使用4800円
  CreditCard card(5000, 4800);
  // ICカード : 残高300円
  IC ic(300);

  Checkout(cash, 500);
  Checkout(card, 500);
  Checkout(ic, 500);

  return 0;
}
