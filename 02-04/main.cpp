#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll,
                 int userGuess) {
  Sleep(delayMs);
  fn(roll, userGuess);
}

int main(void) {

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  int userGuess = 0;
  int roll = 0;

  srand((unsigned int)time(NULL));

  printf("丁半ゲーム\n");
  printf("予想を入力してね（半=奇数=1 / 丁=偶数=0）: ");
  scanf_s("%d", &userGuess);

  roll = (rand() % 6) + 1;

  printf("サイコロを振っています...\n");

  auto showResult = [](int roll, int userGuess) {
    int isOdd = (roll % 2 == 1);

    printf("出目は %d でした。\n", roll);

    if ((userGuess == 1 && isOdd) || (userGuess == 0 && !isOdd)) {
      printf("正解\n");
    } else {
      printf("不正解\n");
    }
  };

  DelayReveal(showResult, 3000, roll, userGuess);

  return 0;
}
