#ifndef T1_ISOSCALE_H
#define T1_ISOSCALE_H
#include "base-types.h"
#include "shape.h"
namespace turkin
{
  void isoScaleWithVerify(Shape * shape, scale_t scale);
  void isoScaleWithoutVerify(Shape * shape, scale_t scale);
}
#endif

