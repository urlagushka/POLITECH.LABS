#include <iostream>
#include <fstream>
#include <cstdlib>
#include "dynamicArray.h"
#include "downSequence.h"
#include "repeatedNums.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "invalid amount of arguments\n";
    return 1;
  }

  const size_t constSize = 10;
  int constArray[constSize] = {4, 3, 2, 1, 5, 2, 1, 9, 9, 9};

  size_t dynamicSize = 0;
  std::cin >> dynamicSize;
  if (!std::cin)
  {
    std::cerr << "incorrect input\n";
    return 2;
  }
  turkin::Array dynamicArray(dynamicSize);
  std::srand(time(nullptr));
  for (size_t i = 0; i < dynamicSize; i++)
  {
    dynamicArray.size++;
    dynamicArray.data[i] = std::rand() % 10;
  }

  std::string filename = argv[1];
  std::fstream input(filename);
  size_t fileSize = 0;
  if (!input.is_open())
  {
    std::cerr << "cannot open file\n";
    return 3;
  }
  input >> fileSize;
  if (!input)
  {
    std::cerr << "empty file\n";
    return 4;
  }
  turkin::Array fileArray(fileSize);
  for (size_t i = 0; i < fileSize; i++)
  {
    fileArray.size++;
    input >> fileArray.data[i];
  }
  size_t constSequence = turkin::getDownSequence(constArray, constSize);
  size_t dynamicSequence = turkin::getDownSequence(dynamicArray);
  size_t fileSequence = turkin::getDownSequence(fileArray);
  try
  {
    bool constRepeated = turkin::getRepeatedNums(constArray, constSize, 0, constSize);
    bool dynamicRepeated = turkin::getRepeatedNums(dynamicArray, 0, dynamicArray.size);
    bool fileRepeated = turkin::getRepeatedNums(fileArray, 0, fileArray.size);
    std::cout << constSequence << "\t" << dynamicSequence << "\t" << fileSequence << "\n";
    std::cout << constRepeated << "\t" << dynamicRepeated << "\t" << fileRepeated << "\n";
  }
  catch (const std::invalid_argument & error)
  {
    std::cerr << error.what() << "\n";
    return 5;
  }
  return 0;
}
