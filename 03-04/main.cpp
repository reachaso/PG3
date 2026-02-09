#include "area/Circle.h"
#include "area/IShape.h"
#include "area/Rectangle.h"
#include <memory>
#include <vector>

using namespace std;

int main() {
  vector<unique_ptr<IShape>> shapes;
  shapes.emplace_back(make_unique<Circle>(5.0f));
  shapes.emplace_back(make_unique<Rectangle>(4.0f, 3.0f));

  for (auto& shape : shapes) {
    shape->Size();
    shape->Draw();
  }

  return 0;
}
