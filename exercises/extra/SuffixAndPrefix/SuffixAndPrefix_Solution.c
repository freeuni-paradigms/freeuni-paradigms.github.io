#include "SuffixAndPrefix.h"

char* SuffAndPreff(char* str, int N){
    if (N > strlen(str))
        return str;
    bool isSame = true;
    for(int i = 0; i < N; i++){
        if(str[i] != str[strlen(str) - (i + 1)]){
            isSame = false;
            break;
        }
    }
    if(isSame){
        char* answer = malloc(sizeof(char) * (strlen(str) - 2*N + 1));
        strncpy(answer, str + N, strlen(str) - 2*N);
        answer[strlen(str) - 2*N] = '\0';
        return answer;
    }
    return str;
}