#ifndef COMPUTE_H
#define COMPUTE_H
namespace turkin
{
  struct LengthOfSequence
    {
    void operator()(int current);
    unsigned int isSame(int current);
    unsigned int getMaxAmount();
    bool checkLimit(unsigned int num);

    int last = 0;
    unsigned int currentAmount = 0;
    unsigned int maxAmount = 0;
    unsigned int count = 0;
  };

  struct PreMaximum
    {
    void operator()(int current);
    int getPreMaximum();

    int allMax = 0;
    int beforeMax = 0;
  };
}
#endif
