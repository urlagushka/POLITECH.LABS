#ifndef TABLEINFERENCE_H
#define TABLEINFERENCE_H
#include <cstddef>
#include <iostream>
namespace turkin
{
  void printTable(std::ostream & output, double lhs, double rhs, double step, double error, size_t maxAmount);
}
#endif
