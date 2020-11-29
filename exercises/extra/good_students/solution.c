#include "good_students.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

char* GoodStudents(void* ptr){
    char* answer = strdup("");
    char* curr = ptr;
    while(*curr != '\0'){
        char* student = curr;
        int score = *((unsigned char*)(student + strlen(student) + 1));
        if(score >= 150){
            if(strlen(answer) == 0){
                answer = realloc(answer, strlen(student) + 1);
                strcpy(answer, student);
            } else {
                answer = realloc(answer, strlen(answer) + 1 + strlen(student) + 1);
                strcpy(answer + strlen(answer) + 1, student);
                answer[strlen(answer)] = ' ';
            }
        }
        curr += strlen(student) + 2;
    }
    return answer;
}