#include "repeatedNums.h"
#include <cstddef>
#include <stdexcept>

bool turkin::getRepeatedNums(const Array & array, size_t begin, size_t end)
{
  return turkin::getRepeatedNums(array.data, array.size, begin, end);
}

bool turkin::getRepeatedNums(const int * array, size_t size, size_t begin, size_t end)
{
  if (end > size)
  {
    throw std::invalid_argument("invalid range");
  }
  size_t amount = 0;
  for (size_t i = begin; i < end; i++)
  {
    amount = 0;
    for (size_t j = begin; j < end; j++)
    {
      if (array[i] == array[j])
      {
        amount++;
      }
    }
    if (amount > 1)
    {
      return true;
    }
  }
  return false;
}
