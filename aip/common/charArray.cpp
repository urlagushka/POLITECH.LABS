#include "charArray.h"
#include <limits>
#include <stdexcept>

turkin::CharArray::CharArray(size_t cap):
  data(new char[cap]()),
  size(0),
  capacity(cap)
{}

turkin::CharArray::~CharArray()
{
  delete [] data;
}

void turkin::extend(turkin::CharArray & array, size_t addition)
{
  size_t capacity = array.capacity + addition;
  if (capacity == std::numeric_limits< size_t >::max())
  {
    throw std::overflow_error("out of size");
  }

  char * extendArray = new char[capacity]();
  for (size_t i = 0; i < array.size; i++)
  {
    extendArray[i] = array.data[i];
  }
  array.capacity = capacity;
  delete [] array.data;
  array.data = extendArray;
}
