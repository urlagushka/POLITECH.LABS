#include "circle.h"
#include "base-types.h"

turkin::Circle::Circle(turkin::point_t position, double radius):
  Rectangle({position.x - radius, position.y - radius}, {position.x + radius, position.y + radius})
{}

double turkin::Circle::getArea() const
{
  return PI * rect_.width * rect_.width / 2 / 2;
}

