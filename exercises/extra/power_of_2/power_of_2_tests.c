#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h> 

#include "power_of_2.h"

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

bool test_one() {
    ASSERT(next_power_of_2(1) == 1);

    return true;
}

bool test_two() {
    ASSERT(next_power_of_2(2) == 2);
    ASSERT(next_power_of_2(3) == 2);

    return true;
}

bool test_three() {
    for (int i = 4; i < 8; i++) {
        ASSERT(next_power_of_2(i) == 3);
    }

    return true;
}

bool test_ten() {
    for (int i = 512; i < 1024; i++) {
        ASSERT(next_power_of_2(i) == 10);
    }

    return true;
}

int main() {
    Test("#0: first power", test_one);
    Test("#1: second power", test_two);
    Test("#2: third power", test_three);
    Test("#3: tenth power", test_ten);

    return 0;
}