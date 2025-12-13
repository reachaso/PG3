#include <Windows.h>
#include <stdio.h>

int main() {
  // 何時間働くか
  int workTime = 9;

  // 一般的な賃金体系(時給1226円)
  int hourly_wage = 1226;

  // 再帰的な賃金体系 (最初 : 100円 2回目以降 : 前の1時間で貰った時給 * 2 -
  // 50円)
  int recursion = 100;

  for (int i = 1; i <= workTime; ++i) {
    printf("\n%dhour\n", i);
    printf("hourly_wage : %d\n", hourly_wage * i);
    if (i == 1) {
      printf("recursion : %d\n", recursion);
    } else {
      recursion = recursion * 2 - 50; // 再帰的な計算を修正
      printf("recursion : %d\n", recursion);
    }
  }

  return 0;
}
