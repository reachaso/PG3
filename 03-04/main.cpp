#include "area/Circle.h"
#include "area/Rectangle.h"

using namespace std;

int main() {
  Circle circle(5.0);
  circle.Size();
  circle.Draw();

  Rectangle rectangle(4.0, 3.0);
  rectangle.Size();
  rectangle.Draw();

  return 0;
}
