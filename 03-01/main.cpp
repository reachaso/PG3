#include <chrono>
#include <thread>
#include <windows.h>
#include "Enemy/Enemy.h"

int main() {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  Enemy enemy;

  for (int i = 0; i < 6; ++i) {
    enemy.Update();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }

  return 0;
}
