#include "set_zero.h"

int SetZero(int number, int index){
  unsigned int mask = (1 << (32 - index - 1)) - 1;
  unsigned int k = number & mask;
  if (index == 0){
	  return k;
  }
  unsigned int n = (unsigned int)number;
  n = n >> (32 - index);
  n = n << (32 - index);
  unsigned int result = k + n;
  return result;
}
