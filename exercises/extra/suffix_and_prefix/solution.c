#include "suffix_and_prefix.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* SuffAndPreff(char* str, int N){
    if (2*N > strlen(str))
        return strdup("");
    bool is_same = true;
    for(int i = 0; i < N; i++){
        if(str[i] != str[strlen(str) - (i + 1)]){
            is_same = false;
            break;
        }
    }
    if(is_same){
        char* answer = malloc(sizeof(char) * (strlen(str) - 2*N + 1));
        strncpy(answer, str + N, strlen(str) - 2*N);
        answer[strlen(str) - 2*N] = '\0';
        return answer;
    }
    return str;
}