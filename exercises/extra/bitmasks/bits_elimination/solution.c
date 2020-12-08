#include "bits_elimination.h"

#include <math.h>

int EliminateBits(int num, int left_boundary, int right_boundary){
    int eliminator = __INT_MAX__;

    for(int i = right_boundary; i <= left_boundary; i++){
        int bit_index = pow(2, i);
        eliminator -= bit_index;
        num = num & eliminator;
        eliminator += bit_index;
    }

    return num;
}