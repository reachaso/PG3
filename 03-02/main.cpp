#include "cf_Min/cf_Min.h"
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif

  int int1 = 10;
  int int2 = 20;

  float float1 = 5.5f;
  float float2 = 3.3f;

  double double1 = 2.2;
  double double2 = 4.4;

  cf_Min<int, int> minInt(int1, int2);
  printf("Min(%d, %d) = %d\n", int1, int2, minInt.Min());
  cf_Min<float, float> minFloat(float1, float2);
  printf("Min(%.2ff, %.2ff) = %.2f\n", float1, float2, minFloat.Min());
  cf_Min<double, double> minDouble(double1, double2);
  printf("Min(%.2f, %.2f) = %.2f\n", double1, double2, minDouble.Min());

  cf_Min<int, float> minIntFloat(int1, float2);
  printf("Min(%d, %.2ff) = %.2f\n", int1, float2, minIntFloat.Min());
  cf_Min<float, double> minFloatDouble(float1, double2);
  printf("Min(%.2ff, %.2f) = %.2f\n", float1, double2, minFloatDouble.Min());
  cf_Min<int, double> minIntDouble(int2, double1);
  printf("Min(%d, %.2f) = %.2f\n", int2, double1, minIntDouble.Min());



  return 0;
}
