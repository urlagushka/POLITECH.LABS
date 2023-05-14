#include <iostream>
#include <cstddef>
#include <cstring>
#include "matrixReadWrite.h"
#include "matrixOperations.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "invalid amount of arguments\n";
    return 1;
  }
  size_t mx = 0;
  size_t my = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "cannot open file\n";
    return 1;
  }
  input >> mx >> my;
  if (!input)
  {
    std::cerr << "empty file\n";
    return 1;
  }
  if (mx * my > 1000)
  {
    std::cerr << "out of range\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int constMatrix[1000];
    for (size_t i = 0; i < mx * my; i++)
    {
      input >> constMatrix[i];
      if (!input)
      {
        std::cerr << "memory error\n";
        return 1;
      }
    }
    std::ofstream output(argv[3]);
    output << turkin::getNotZeroLines(constMatrix, mx, my) << " " << turkin::getSameSumLines(constMatrix, mx, my);
  }
  else
  {
    int * dynamicMatrix = new int[mx * my];
    turkin::set(dynamicMatrix, mx * my, input);
    if (!input)
    {
      std::cerr << "memory error\n";
      delete [] dynamicMatrix;
      return 1;
    }
    std::ofstream output(argv[3]);
    int * smoothedMatrix = nullptr;
    try
    {
      smoothedMatrix = new int[mx * my];
      turkin::getSmoothedMatrix(dynamicMatrix, smoothedMatrix, mx, my);
      output << turkin::getSaddlePoints(dynamicMatrix, mx, my) << " " << turkin::getSumOfModules(smoothedMatrix, mx) << "\n";
      delete [] smoothedMatrix;
      delete [] dynamicMatrix;
    }
    catch (...)
    {
      delete [] smoothedMatrix;
      delete [] dynamicMatrix;
    }
  }
  return 0;
}
