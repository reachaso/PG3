#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
  Rectangle(double width, double height);

  void Size() override;
  void Draw() override;

private:
  double m_width;
  double m_height;
  double m_area;
};
