#include <Windows.h>
#include <stdio.h>

int main() {
  // 何時間働くか
  int workTime = 9;
  // 一般的な賃金体系(時給1226円)
  int hourly_wage = 1226;
  // 再帰的な賃金体系 (最初 : 100円 2回目以降 : 前の1時間で貰った時給 * 2 - 50円)
  int recursionHourly = 100;
  // 合計金額を格納する変数
  int normalTotal = 0;
  int recursionTotal = 0;

  for (int i = 1; i <= workTime; ++i) {
    normalTotal += hourly_wage;
    recursionTotal += recursionHourly;

    printf("\n%dhour\n", i);
    printf("hourly_wage (per hour) : %d\n", hourly_wage);
    printf("recursion (per hour) : %d\n", recursionHourly);
    printf("hourly_wage (total) : %d\n", normalTotal);
    printf("recursion (total) : %d\n", recursionTotal);

    recursionHourly = recursionHourly * 2 - 50; // 再帰的な計算を修正
  }

  return 0;
}
