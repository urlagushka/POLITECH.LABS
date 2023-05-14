#ifndef T1_ELLIPSE_H
#define T1_ELLIPSE_H
#include "base-types.h"
#include "shape.h"
namespace turkin
{
  class Ellipse: public Shape
  {
    public:
      Ellipse(point_t one, double nr1, double nr2);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scaleWithoutVerify(double ds) override;
      Shape * clone() const override;
    private:
      rectangle_t rect_;
      double r1, r2;
  };
}
#endif

