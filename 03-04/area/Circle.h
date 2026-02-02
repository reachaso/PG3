#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
  Circle(double radius);

  void Size() override;
  void Draw() override;

private:
  double m_radius;
  double m_area;
};
