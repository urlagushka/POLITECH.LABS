#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <queue.hpp>
#include <stack.hpp>
#include "data-type.hpp"
#include "exp-work.hpp"
#include <dictionary/forward-list/oneway-list.hpp>

int main(int argc, char * argv[])
{
  using namespace turkin;

  std::ifstream file;
  if (argc == 2)
  {
    file.open(argv[1]);
    if (!file.is_open())
    {
      std::cerr << "cannot open file\n";
      return 1;
    }
  }

  std::istream & in = (argc == 2) ? file : std::cin;
  Stack< long long > answers;
  std::string dirt;
  try
  {
    while (in)
    {
      std::getline(in, dirt);
      if (!in)
      {
        break;
      }
      if (!dirt.length())
      {
        continue;
      }
      dirt += "\n";
      Queue< calc_t< PINF > > input = str2Inf(dirt);
      Queue< calc_t< PFIX > > output = inf2Post(input);
      answers.push(post2Result(output));
    }
  }
  catch (const std::exception & error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }

  if (!answers.isEmpty())
  {
    std::cout << answers.get();
    answers.pop();
  }
  while (!answers.isEmpty())
  {
    std::cout << " " << answers.get();
    answers.pop();
  }
  std::cout << "\n";
  return 0;
}
