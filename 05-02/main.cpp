#include <windows.h>

using namespace std;

int main() {

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  return 0;
}

