#include "cosh.h"
#include <stdexcept>

double turkin::cosh(double x, double error, size_t maxAmount)
{
  double result = 1.0;
  double increment = 0.0;
  double factorial = 2.0;
  x = x * x;
  for (size_t i = 2; i < maxAmount; i++)
  {
    increment = x / factorial;
    result = result + increment;
    x = x * x * x;
    factorial = factorial * (i + 1);
  }
  if (increment > error)
  {
    throw std::out_of_range("low precision");
  }
  return result;
}
