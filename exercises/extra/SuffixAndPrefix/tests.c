#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "SuffixAndPrefix.h"


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

bool test1(){
    bool answer = strcmp(SuffAndPreff(strdup("aba"), 1), strdup("b")) == 0;
    return answer;
}

bool test2(){
    bool answer = strcmp(SuffAndPreff(strdup("baab"), 2), strdup("")) == 0;
    return answer;
}

bool test3(){
    bool answer = strcmp(SuffAndPreff(strdup("Preffix"), 1), strdup("Preffix")) == 0;
    return answer;
}

bool test4(){
    bool answer = strcmp(SuffAndPreff(strdup("FIXIF"), 2), strdup("X")) == 0;
    return answer;
}

bool test5(){
    bool answer = strcmp(SuffAndPreff(strdup("MARIAM"), 2), strdup("RI")) == 0;
    return answer;
}

bool test6(){
    bool answer = strcmp(SuffAndPreff(strdup("123454321"), 3), strdup("454")) == 0;
    return answer;
}

int main(){
  Test(" str = aba, N = 1", test1);
  Test(" str = baab, N = 2", test2);
  Test(" str = Preffix, N = 8", test3);
  Test(" str = FIXIF, N = 2", test4);
  Test(" str = MARIAM, N = 2", test5);
  Test(" str = 123454321, N = 3", test6);
  return 0;
}