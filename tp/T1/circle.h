#ifndef T1_CIRCLE_H
#define T1_CIRCLE_H
#include "rectangle.h"
namespace turkin
{
  class Circle: public Rectangle
  {
    public:
      Circle(turkin::point_t position, double radius);
      double getArea() const override;
  };
}
#endif

