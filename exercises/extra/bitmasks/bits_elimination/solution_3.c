#include "bits_elimination.h"

int EliminateBits(int num, int left_boundary, int right_boundary){
    int left = left_boundary == 31 ? 0 : (num >> left_boundary + 1) << (left_boundary + 1);
    int right = num & (((1 << right_boundary) - 1));
    return   num & (left + right);
}
