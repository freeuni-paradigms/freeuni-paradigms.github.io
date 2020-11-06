#include "power_of_2.h"

int next_power_of_2(int x) {
    int res = 0;

    while (x != 0) {
        x >>= 1;
        res++;
    }
    return res;
}