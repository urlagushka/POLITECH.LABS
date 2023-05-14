#include "isoscale.h"
#include <stdexcept>
#include "base-types.h"

void turkin::isoScaleWithVerify(Shape * shape, scale_t scale)
{
  if (scale.ds <= 0)
  {
    throw std::logic_error("bad scale size");
  }
  isoScaleWithoutVerify(shape, scale);
}

turkin::point_t diffPoint(const turkin::point_t & one, const turkin::point_t & two)
{
  return {one.x - two.x, one.y - two.y};
}

turkin::point_t resizePoint(const turkin::point_t & point, const turkin::scale_t & scale)
{
  return {diffPoint(point, scale.pos).x * scale.ds, diffPoint(point, scale.pos).y * scale.ds};
}

void turkin::isoScaleWithoutVerify(turkin::Shape * shape, turkin::scale_t scale)
{
  point_t pos = shape->getFrameRect().pos;
  shape->move(scale.pos);
  shape->scaleWithoutVerify(scale.ds);
  shape->move(resizePoint(pos, scale).x, resizePoint(pos, scale).y);
}

