#include "downSequence.h"
#include <cstddef>
#include <algorithm>

size_t turkin::getDownSequence(const Array & array)
{
  return turkin::getDownSequence(array.data, array.size);
}

size_t turkin::getDownSequence(const int * array, size_t size)
{
  size_t maxLen = 0;
  size_t curLen = 0;
  for (size_t i = 1; i < size; i++)
  {
    if (array[i] < array[i - 1])
    {
      curLen++;
    }
    else
    {
      maxLen = std::max(curLen, maxLen);
      curLen = 0;
    }
  }
  maxLen = std::max(curLen, maxLen);
  return maxLen + 1;
}
