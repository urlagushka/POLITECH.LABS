#include "matrixReadWrite.h"

void turkin::set(int * matrix, size_t size, std::ifstream & input)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
  }
}

void turkin::set(int * matrix, size_t mx, size_t my, int data)
{
  matrix[mx * mx + my] = data;
}

int turkin::get(const int * matrix, size_t mx, size_t my)
{
  return matrix[mx * mx + my];
}
