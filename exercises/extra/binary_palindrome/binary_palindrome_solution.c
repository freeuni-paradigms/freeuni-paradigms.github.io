#include <stdbool.h>
#include "binary_palindrome.h"

bool is_bit_one(unsigned int x, int index) {
    return x & (1 << index);
}

bool is_not_equal_bit(unsigned int x, int i1, int i2) {
    return is_bit_one(x, i1) != is_bit_one(x, i2);
}

bool is_binary_palindrome(unsigned int x) {
    int left = 0;
    int right = 31;

    while (left < right) {
        if (is_not_equal_bit(x, left, right)) {
            return false;
        }

        left++;
        right--;
    }
    return true;
}