#include "num_to_bits.h"

#include <stdlib.h>
#include <stdio.h>

void AppendBit(char** answer, char addition, size_t len){
    *answer = realloc(*answer, len);
    (*answer)[--len] = addition;
}

char* NumToBits(void* num, size_t bytes){
    char* ptr = num + bytes - 1;
    char* answer = NULL;
    int len_count = 0;

    for (int i = bytes - 1 ; i >= 0; i--){
        unsigned char currByte = *((unsigned char*)ptr);
        for(int j = 0; j < 8; j++){
            if(currByte & 128)
                AppendBit(&answer , '1', len_count*8 + j + 1);
            else
                AppendBit(&answer , '0', len_count*8 + j + 1); 
            currByte = currByte << 1;    
        }
        ptr--;
        len_count++;
    }
    
    return answer;
}

char* ShortToBits(short num){
    return NumToBits(&num, sizeof(short));
}

char* IntToBits(int num){
    return NumToBits(&num, sizeof(int));
}