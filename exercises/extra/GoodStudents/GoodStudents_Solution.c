#include "GoodStudents.h"

char** GoodStudents(void* ptr){
    char** answer = malloc(sizeof(char*));
    int i = 0;
    char* curr = ptr;
    while(*curr != '\0'){
        char* student = curr;
        int score = *((unsigned char*)(student + strlen(student) + 1));
        if(score >= 150){
            answer[i++] = student;
            answer = realloc(answer, i*sizeof(char*));
        }
        // printf("%s - %d\n", student, score);
        curr += strlen(student) + 2;
    }
    return answer;
}