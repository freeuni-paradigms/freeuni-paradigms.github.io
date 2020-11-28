#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "suffix_and_prefix.h"


#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

void Test(char* name, bool(*Test_fn)()) {
  printf("++ RUNNING Test: %s\n", name);
  if (Test_fn()) {
    printf("-- Test %s: SUCCEEDED\n", name);
  } else {
    printf("-- Test %s: FAILED\n", name);
  }
  printf("\n");
}

bool Test1(){
    bool answer = strcmp(SuffAndPreff("aba", 1), "b") == 0;
    return answer;
}

bool Test2(){
    bool answer = strcmp(SuffAndPreff("baab", 2), "") == 0;
    return answer;
}

bool Test3(){
    bool answer = strcmp(SuffAndPreff("Preffix", 1), "Preffix") == 0;
    return answer;
}

bool Test4(){
    bool answer = strcmp(SuffAndPreff("FIXIF", 2), "X") == 0;
    return answer;
}

bool Test5(){
    bool answer = strcmp(SuffAndPreff("MARIAM", 2), "RI") == 0;
    return answer;
}

bool Test6(){
    bool answer = strcmp(SuffAndPreff("123454321", 3), "454") == 0;
    return answer;
}

bool Test7(){
    bool answer = strcmp(SuffAndPreff("abcdefg", 4), "") == 0;
    return answer;
}

int main(){
  Test(" str = aba, N = 1", Test1);
  Test(" str = baab, N = 2", Test2);
  Test(" str = Preffix, N = 8", Test3);
  Test(" str = FIXIF, N = 2", Test4);
  Test(" str = MARIAM, N = 2", Test5);
  Test(" str = 123454321, N = 3", Test6);
  Test(" str = abcdefg, N = 4", Test7);
  return 0;
}