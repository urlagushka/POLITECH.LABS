#include <iostream>
#include "tableInference.h"

int main()
{
  size_t maxAmount = 0;
  double lhs = 0.0;
  double rhs = 0.0;
  const double step = 0.01;
  const double error = 0.0001;
  std::cin >> lhs >> rhs >> maxAmount;
  if (!std::cin || lhs < -1.0 || rhs > 1.0 || lhs > rhs)
  {
    std::cerr << "incorrect input\n";
    return 1;
  }
  turkin::printTable(std::cout, lhs, rhs, step, error, maxAmount);
  return 0;
}
