#ifndef T1_READWRITESHAPES_H
#define T1_READWRITESHAPES_H
#include <istream>
#include "shape.h"
#include "compositeShape.h"
namespace turkin
{
   Shape * createRectangle(std::istream & input);
   Shape * createSquare(std::istream & input);
   Shape * createEllipse(std::istream & input);
   Shape * createCircle(std::istream & input);
   scale_t getScale(std::istream & input);
   void printAreaPoints(std::ostream & output, const CompositeShape & compositeShape);
}
#endif

