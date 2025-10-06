#include <stdio.h>

using namespace std;

template <typename T> T Min(T a, T b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int main() {

  int a = 5;
  int b = 1;

  printf("int : (a : %d , b : %d)\n", a, b);
  printf("Min : %d\n", Min(a, b));

  float c = 2.0f;
  float d = 8.0f;

  printf("float : (c : %f , d : %f)\n", c, d);
  printf("Min : %f\n", Min(c, d));

  double e = 4.0;
  double f = 10.0;

  printf("double : (e : %f , f : %f)\n", e, f);
  printf("Min : %f\n", Min(e, f));

  return 0;
}
