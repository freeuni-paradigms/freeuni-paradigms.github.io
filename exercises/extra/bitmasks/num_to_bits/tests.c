#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "num_to_bits.h"


#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

bool Test1(){
  return strcmp(ShortToBits(0), "0000000000000000") == 0;
}

bool Test2(){
  return strcmp(ShortToBits(-495), "1111111000010001") == 0;
}

bool Test3(){
  return strcmp(ShortToBits(6417), "0001100100010001") == 0;
}

bool Test4(){
  return strcmp(IntToBits(4879452), "00000000010010100111010001011100") == 0;
}

bool Test5(){
  return strcmp(IntToBits(-4879452), "11111111101101011000101110100100") == 0;
}

bool Test6(){
  return strcmp(IntToBits(123456789), "00000111010110111100110100010101") == 0;
}
   

int main(){
  Test("Test1 short num = 0", Test1);
  Test("Test2 short num = -495", Test2);
  Test("Test3 short num = 6417", Test3);
  Test("Test4 int num = 4879452", Test4);
  Test("Test5 int num = -4879452", Test5);
  Test("Test6 int num = 123456789", Test6);
  return 0;
}

