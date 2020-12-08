#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "bits_elimination.h"


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
  ASSERT(EliminateBits(25, 3, 0) == 16)
  return true;
}

bool Test2(){
  ASSERT(EliminateBits(1049, 11, 4) == 9)
  return true;
}

bool Test3(){
  ASSERT(EliminateBits(1234567, 10, 7) == 1232903)
  return true;
}

bool Test4(){
  ASSERT(EliminateBits(2165421365, 31, 0) == 0)
  return true;
}

bool Test5(){
  ASSERT(EliminateBits(2165421365, 31, 9) == 309)
  return true;
}

int main(){
  Test("Test1 num = 25 left_boundary = 3 right_boundary = 0", Test1);
  Test("Test2 num = 1049 left_boundary = 11 right_boundary = 4", Test2);
  Test("Test3 num = 1234567 left_boundary = 10 right_boundary = 7", Test3);
  Test("Test4 num = 2165421365 left_boundary = 31 right_boundary = 0", Test4);
  Test("Test5 num = 2165421365 left_boundary = 31 right_boundary = 9", Test5);
  return 0;
}

