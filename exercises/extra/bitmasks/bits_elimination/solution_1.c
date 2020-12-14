#include "bits_elimination.h"

int EliminateBits(int num, int left_boundary, int right_boundary){
    int eliminator = __INT_MAX__; // = (1 << 31) - 1

    for(int i = right_boundary; i <= left_boundary; i++){
        int power_of_two = 1 << i;
        eliminator -= power_of_two;
        num = num & eliminator;
        eliminator += power_of_two;
    }

    return num;
}
