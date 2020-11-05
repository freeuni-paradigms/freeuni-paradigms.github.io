#include "setZero.h"

int setZero(int number, int index){
  unsigned int mask = 1;
  mask = mask << (32 - index - 1);
  mask = mask - 1;
  unsigned int k = number & mask;
  if (index == 0) return k;
  unsigned int n = (unsigned int)number;
  n = n >> (32 - index);
  n = n << (32 - index);
  unsigned int result = k + n;
  return result;
}
