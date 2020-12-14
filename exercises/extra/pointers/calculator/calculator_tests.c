#include "calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

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

bool test_zero() {
    char * expression = "0+0";

    ASSERT(calculate(expression) == 0);

    return true;
}

bool test_easy() {
    char * expression = "1+1";
    ASSERT(calculate(expression) == 2);

    expression = "3-2";
    ASSERT(calculate(expression) == 1);

    expression = "6+3";
    ASSERT(calculate(expression) == 9);

    expression = "2-7";
    ASSERT(calculate(expression) == -5);

    expression = "13+23";
    ASSERT(calculate(expression) == 36);

    expression = "19+71";
    ASSERT(calculate(expression) == 90);

    expression = "13-23";
    ASSERT(calculate(expression) == -10);

    expression = "71-12";
    ASSERT(calculate(expression) == 59);

    return true;
}

bool test_medium() {
    char * expression = "1+12+13";
    ASSERT(calculate(expression) == 26);

    expression = "10+10+10";
    ASSERT(calculate(expression) == 30);

    expression = "1+12-13";
    ASSERT(calculate(expression) == 0);

    expression = "10-10+10";
    ASSERT(calculate(expression) == 10);

    expression = "13-3-1";
    ASSERT(calculate(expression) == 9);

    expression = "11+21+31+41";
    ASSERT(calculate(expression) == 104);

    return true;
}

bool test_hard() {
    char * expression = "30+40+50+60";
    ASSERT(calculate(expression) == 180);

    expression = "35+25+25+5+10";
    ASSERT(calculate(expression) == 100);

    expression = "35+25-25-5+10";
    ASSERT(calculate(expression) == 40);

    return true;
}

int main() {
    Test("zero", test_zero);
    Test("easy", test_easy);
    Test("medium", test_medium);
    Test("hard", test_hard);

    return 0;
}
