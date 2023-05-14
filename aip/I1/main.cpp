#include "compute.h"
#include <iostream>

int main()
{
  int current = 1;
  turkin::LengthOfSequence len;
  turkin::PreMaximum max;

  while (current && std::cin)
  {
    std::cin >> current;
    try
    {
      len(current);
      max(current);
    }
    catch (std::overflow_error & error)
    {
      std::cout << error.what() << std::endl;
      return 2;
    }
  }

  if (!std::cin)
  {
    std::cout << "incorrect data\n";
    return 1;
  }
  std::cout << "MaxAmount: " << len.getMaxAmount() << "\tBeforeMax: " << max.getPreMaximum() << std::endl;
  return 0;
}
