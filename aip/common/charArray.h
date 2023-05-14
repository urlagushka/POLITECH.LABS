#ifndef CHARARRAY_H
#define CHARARRAY_H

#include <cstddef>
namespace turkin
{
  struct CharArray
  {
    explicit CharArray(size_t cap);
    ~CharArray();

    char * data;
    size_t size;
    size_t capacity;
  };

  void extend(turkin::CharArray & array, size_t addition);
}

#endif
