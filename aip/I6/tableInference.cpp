#include "tableInference.h"
#include <iomanip>
#include "cosh.h"

void printRow(std::ostream & output, double x, double cosh)
{
  output << std::setw(4) << x << std::setw(6) << std::setprecision(3) << cosh << "\n";
}

void turkin::printTable(std::ostream & output, double lhs, double rhs, double step, double error, size_t maxAmount)
{
  for (double x = lhs; x <= rhs; x = x + step)
  {
    try
    {
      double result = turkin::cosh(x, error, maxAmount);
      printRow(output, x, result);
    }
    catch (const std::out_of_range & coshError)
    {
      output << coshError.what() << "\n";
    }
  }
}
