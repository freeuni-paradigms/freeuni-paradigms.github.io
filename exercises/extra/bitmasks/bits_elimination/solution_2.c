#include "bits_elimination.h"

int EliminateBits(int num, int left_boundary, int right_boundary){
    for(int i = right_boundary; i <= left_boundary; i++)
        num -= num & (1 << i);

    return num;
}
