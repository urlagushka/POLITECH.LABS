#ifndef DOWNSEQUENCE_H
#define DOWNSEQUENCE_H
#include <cstddef>
#include "dynamicArray.h"
namespace turkin
{
  size_t getDownSequence(const Array & array);
  size_t getDownSequence(const int * array, size_t size);
}
#endif
