#include "rectangle.h"
#include <stdexcept>

double turkin::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

turkin::rectangle_t turkin::Rectangle::getFrameRect() const
{
  return rect_;
}

void turkin::Rectangle::move(double dx, double dy)
{
  rect_.pos.x = rect_.pos.x + dx;
  rect_.pos.y = rect_.pos.y + dy;
}

void turkin::Rectangle::move(point_t position)
{
  rect_.pos = position;
}

void turkin::Rectangle::scaleWithoutVerify(double ds)
{
  rect_.width = rect_.width * ds;
  rect_.height = rect_.height * ds;
}

turkin::Rectangle::Rectangle(point_t one, point_t two):
  rect_({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{
  if (rect_.width <= 0.0 || rect_.height <= 0.0)
  {
    throw std::logic_error("bad rectangle size");
  }
}

turkin::Shape * turkin::Rectangle::clone() const
{
  return new Rectangle(rect_);
}

turkin::Rectangle::Rectangle(rectangle_t rectangle):
  rect_(rectangle)
{}

