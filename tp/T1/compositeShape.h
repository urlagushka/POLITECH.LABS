#ifndef T1_COMPOSITESHAPE_H
#define T1_COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"
namespace turkin
{
  class CompositeShape
  {
    public:
      explicit CompositeShape(size_t capacity);
      CompositeShape(const CompositeShape & compositeShape);
      CompositeShape(Shape ** shapes, size_t capacity, size_t size);
      ~CompositeShape();
      CompositeShape & operator=(const CompositeShape & compositeShape);
      CompositeShape & operator=(CompositeShape && compositeShape) noexcept;
      Shape * operator[](size_t id);
      const Shape * operator[](size_t id) const;
      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(point_t position);
      void move(double dx, double dy);
      void scale(scale_t scale);
      void push_back(Shape * shp);
      void push_back(const Shape * shp);
      void pop_back();
      CompositeShape * clone() const;
      Shape * at(size_t id);
      const Shape * at(size_t id) const;
      bool empty() const;
      size_t size() const;
      void scaleWithVerify(scale_t scale);
      void scaleWithoutVerify(scale_t scale);
    private:
      Shape ** shapes;
      size_t capacity_;
      size_t size_;
      void freeMemory(Shape ** shp, size_t size) const;
  };
}
#endif

