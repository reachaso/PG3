#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double width, double height)
    : m_width(width), m_height(height), m_area(0.0) {}

void Rectangle::Size() { m_area = m_width * m_height; }

void Rectangle::Draw() {
  std::cout << "Rectangle width=" << m_width << " height=" << m_height
            << " area=" << m_area << std::endl;
}
