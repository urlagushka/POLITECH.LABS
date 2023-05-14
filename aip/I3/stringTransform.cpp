#include "stringTransform.h"
#include <cctype>

char * turkin::deleteNumbers(char * destination, const char * source)
{
  size_t q = 0;
  for (const char * i = source; *i != '\0'; i++)
  {
    if (!std::isdigit(*i))
    {
      destination[q++] = *i;
    }
  }
  return destination;
}

bool turkin::isRepeat(const char * source)
{
  size_t amount = 0;
  for (const char * i = source; *i != '\0'; i++)
  {
    amount = 0;
    for (const char * q = source; *q != '\0'; q++)
    {
      if (*i == *q)
      {
        amount++;
      }
    }
    if (amount > 1)
    {
      return true;
    }
    i++;
  }
  return false;
}
