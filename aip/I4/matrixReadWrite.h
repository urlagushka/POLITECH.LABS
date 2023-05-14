#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <fstream>
namespace turkin
{
  void set(int * matrix, size_t size, std::ifstream & input);
  void set(int * matrix, size_t mx, size_t my, int data);
  int get(const int * matrix, size_t mx, size_t my);
}
#endif

