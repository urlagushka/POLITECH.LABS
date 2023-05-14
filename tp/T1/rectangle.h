#ifndef T1_RECTANGLE_H
#define T1_RECTANGLE_H
#include "base-types.h"
#include "shape.h"
namespace turkin
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(point_t one, point_t two);
      explicit Rectangle(rectangle_t rectangle);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scaleWithoutVerify(double ds) override;
      Shape * clone() const override;
    protected:
      rectangle_t rect_;
  };
}
#endif

