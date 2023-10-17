#include "readWriteShapes.h"
#include <istream>
#include <iomanip>
#include "rectangle.h"
#include "ellipse.h"
#include "circle.h"

turkin::Shape * turkin::createRectangle(std::istream & input)
{
  double p[4] {0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  return new Rectangle({p[0], p[1]}, {p[2], p[3]});
}

turkin::Shape * turkin::createSquare(std::istream & input)
{
  double p[3] {0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  return new Rectangle({p[0], p[1]}, {p[0] + p[2], p[1] + p[2]});
}

turkin::Shape * turkin::createEllipse(std::istream & input)
{
  double p[4] {0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  return new Ellipse({p[0], p[1]}, p[3], p[2]);
}

turkin::scale_t turkin::getScale(std::istream & input)
{
  double p[3] {0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  if (p[2] < 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  return {{p[0], p[1]}, p[2]};
}

void printPoints(std::ostream & output, const turkin::Shape * shape)
{
  turkin::rectangle_t rect = shape->getFrameRect();
  output << rect.pos.x - (rect.width / 2.0) << " ";
  output << rect.pos.y - (rect.height / 2.0) << " ";
  output << rect.pos.x + (rect.width / 2.0) << " ";
  output << rect.pos.y + (rect.height / 2.0);
}

void turkin::printAreaPoints(std::ostream & output, const CompositeShape & compositeShape)
{
  output << std::setprecision(1) << std::fixed << compositeShape.getArea();
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    printPoints(output << " ", compositeShape.at(i));
  }
  output << "\n";
}

turkin::Shape * turkin::createCircle(std::istream &input)
{
  double p[3] {0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  return new Circle({p[0], p[1]}, p[2]);
}

