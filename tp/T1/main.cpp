#include <iostream>
#include "base-types.h"
#include "readWriteShapes.h"
#include "compositeShape.h"

int main()
{
  const size_t basicCapacity = 10;
  turkin::CompositeShape compositeShape(basicCapacity);
  std::string line;
  turkin::scale_t scale = {{0.0, 0.0}, 2.0};
  bool isscale = false;
  turkin::Shape * buffer = nullptr;
  while (std::cin)
  {
     std::cin >> line;
     try
     {
       if (line == "RECTANGLE")
       {
         buffer = turkin::createRectangle(std::cin);
         compositeShape.push_back(buffer);
         buffer = nullptr;
       }
       if (line == "SQUARE")
       {
         buffer = turkin::createSquare(std::cin);
         compositeShape.push_back(buffer);
         buffer = nullptr;
       }
       if (line == "ELLIPSE")
       {
         buffer = turkin::createEllipse(std::cin);
         compositeShape.push_back(buffer);
         buffer = nullptr;
       }
       if (line == "CIRCLE")
       {
         buffer = turkin::createCircle(std::cin);
         compositeShape.push_back(buffer);
         buffer = nullptr;
       }
       if (line == "SCALE")
       {
         scale = turkin::getScale(std::cin);
         isscale = true;
         break;
       }
     }
     catch (const std::logic_error & error)
     {
       std::cerr << error.what() << "\n";
       delete buffer;
     }
  }
  if (compositeShape.empty())
  {
    std::cerr << "nothing to scale" << "\n";
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    return 1;
  }
  turkin::printAreaPoints(std::cout, compositeShape);
  try
  {
    compositeShape.scale(scale);
  }
  catch (const std::logic_error & error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  turkin::printAreaPoints(std::cout, compositeShape);
  return 0;
}

