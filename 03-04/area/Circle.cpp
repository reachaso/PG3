#include "Circle.h"
#include <iostream>

Circle::Circle(double radius) : m_radius(radius), m_area(0.0) {}

void Circle::Size() {
  constexpr double pi = 3.141592653589793;
  m_area = pi * m_radius * m_radius;
}

void Circle::Draw() {
  std::cout << "Circle radius=" << m_radius << " area=" << m_area << std::endl;
}
