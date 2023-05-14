#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H
#include <cstddef>
#include "matrixReadWrite.h"
namespace turkin
{
  size_t getNotZeroLines(const int * matrix, size_t mx, size_t my);
  size_t getSameSumLines(const int * matrix, size_t mx, size_t my);
  size_t getSaddlePoints(const int * matrix, size_t mx, size_t my);
  size_t getSumOfModules(const int * matrix, size_t mx);
  int getSumOfLine(const int * matrix, size_t mx, size_t my, size_t line);
  void getSmoothedMatrix(const int * matrix, int * result, size_t mx, size_t my);
}
#endif
