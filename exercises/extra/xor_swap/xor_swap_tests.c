#include "xor_swap.h"

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

bool test_equal_nums() {
    int x = 5;
    int y = x;

    xor_swap(&x, &y);

    ASSERT(x == y);

    return true;
}

bool test_positive_nums() {
    int x = 15;
    int y = 23;

    xor_swap(&x, &y);

    ASSERT(x == 23);
    ASSERT(y == 15);

    return true;
}

bool test_negative_nums() {
    int x = -15;
    int y = -23;

    xor_swap(&x, &y);

    ASSERT(x == -23);
    ASSERT(y == -15);

    return true;
}

bool test_random_nums() {
    for (int i = 0; i < 10; i++) {
        int r1 = rand() % 100;
        int r2 = rand() % 100;

        int x = r1;
        int y = r2;

        xor_swap(&x, &y);

        ASSERT(x == r2);
        ASSERT(y == r1);
    }

    return true;
}

int main() {
    srand(time(0));
    
    Test("#0: equal numbers", test_equal_nums);
    Test("#1: positive numbers", test_positive_nums);
    Test("#2: negative numbers", test_negative_nums);
    Test("#3: random numbers", test_random_nums);

    return 0;
}
