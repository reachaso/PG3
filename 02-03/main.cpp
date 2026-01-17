#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// =========================================================
// 仕様2: 遅延実行関数 DelayReveal()
//  - 判定をすぐ表示せず、指定msだけ待ってから関数を呼び出す
//  - 必ずこの関数を使うこと、という仕様
// =========================================================
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll,
                 int userGuess) {
  Sleep(delayMs);      // 指定時間待つ（ミリ秒）
  fn(roll, userGuess); // 結果表示関数を呼び出す
}

// =========================================================
// 仕様2: 判定関数 ShowResult()
//  - roll(サイコロ出目) と userGuess(1=奇数,0=偶数) を比較
//  - 奇数は roll % 2 == 1、偶数は roll % 2 == 0 で判定
//  - 「出目はXでした。」+「正解/不正解」を2行で出力
// =========================================================
void ShowResult(int roll, int userGuess) {
  int isOdd = (roll % 2 == 1);

  printf("出目は %d でした。\n", roll);

  // userGuess: 1=奇数(半) / 0=偶数(丁)
  if ((userGuess == 1 && isOdd) || (userGuess == 0 && !isOdd)) {
    printf("正解\n");
  } else {
    printf("不正解\n");
  }
}

// =========================================================
//  - srandで乱数初期化
//  - scanf_sで入力（1 or 0）
//  - randで1〜6生成
//  - DelayReveal(ShowResult, 3000, roll, userGuess)
// =========================================================
int main(void) {

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  int userGuess = 0;
  int roll = 0;

  // 乱数初期化
  srand((unsigned int)time(NULL));

  // 入力（厳密チェック不要の想定）
  printf("丁半ゲーム\n");
  printf("予想を入力してね（半=奇数=1 / 丁=偶数=0）: ");
  scanf_s("%d", &userGuess);

  // サイコロの出目（1〜6）
  roll = (rand() % 6) + 1;

  // 3秒後に結果表示
  printf("サイコロを振っています...\n");
  DelayReveal(ShowResult, 3000, roll, userGuess);

  return 0;
}
