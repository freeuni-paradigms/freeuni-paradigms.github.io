#include "binary_palindrome.h"

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
    unsigned int x = 0;
    ASSERT(is_binary_palindrome(x) == true);

    return true;
}

bool test_palindromes() {
    for (int i = 0; i < 16; i++) {
        unsigned int x = (1 << (31 - i)) + (1 << i);
        ASSERT(is_binary_palindrome(x) == true)
    }

    return true;
}

bool test_not_palindromes() {
    for (int i = 0; i < 16; i++) {
        unsigned int x = 1 << i;
        ASSERT(is_binary_palindrome(x) == false)
    }

    return true;
}

bool test_another_palindromes() {
    unsigned int x = (1 << 21) + (1 << 10) + (1 << 26) + (1 << 5);
    ASSERT(is_binary_palindrome(x) == true);

    x = (1 << 21) + (1 << 10) + (1 << 17) + (1 << 14);
    ASSERT(is_binary_palindrome(x) == true);

    x = (1 << 21) + (1 << 10) + (1 << 27) + (1 << 4) + (1 << 23) + (1 << 8);
    ASSERT(is_binary_palindrome(x) == true);

    return true;
}

int main() {
    Test("#0: zero", test_zero);
    Test("#1: palindromes: ", test_palindromes);
    Test("#2: not palindromes: ", test_not_palindromes);
    Test("#3: another palindromes: ", test_another_palindromes);

    return 0;
}
