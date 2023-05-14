#include "compute.h"
#include <algorithm>
#include <stdexcept>
#include <limits>

unsigned int turkin::LengthOfSequence::isSame(int current)
{
  return (current == last && current != 0) ? ++currentAmount : 0;
}

unsigned int turkin::LengthOfSequence::getMaxAmount()
{
  return maxAmount + ((count > 1) ? 1 : 0);
}

void turkin::LengthOfSequence::operator()(int current)
{
  if (checkLimit(count) || checkLimit(maxAmount) || checkLimit(currentAmount))
  {
    throw std::overflow_error("overflow error");
  }
  currentAmount = turkin::LengthOfSequence::isSame(current);
  maxAmount = std::max(maxAmount, currentAmount);
  last = current;
  count++;
}

bool turkin::LengthOfSequence::checkLimit(unsigned int num)
{
  return (num == std::numeric_limits< unsigned int >::max());
}

int turkin::PreMaximum::getPreMaximum()
{
  return beforeMax;
}

void turkin::PreMaximum::operator()(int current)
{
  if (beforeMax < current)
  {
    if (current > allMax)
    {
      beforeMax = allMax;
      allMax = current;
    }
    else
    {
      beforeMax = current;
    }
  }
}
