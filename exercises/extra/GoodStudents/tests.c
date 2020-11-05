#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "GoodStudents.h"


#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

bool test1(){
    char* nika = strdup("Nika");
    char* luka = strdup("Luka");
    char* kosta = strdup("Kosta");
    void* ptr = malloc(sizeof(char)*(strlen(nika) + 2 + strlen(luka) + 2 + strlen(kosta) + 2) + 1);
    
    strcpy(ptr, nika);
    *((unsigned char*)((char*)ptr + strlen(nika) + 1)) = 156;

    strcpy((char*)ptr + strlen(nika) + 2, luka);
    *((unsigned char*)((char*)ptr + strlen(nika) + 2 + strlen(luka) + 1)) = 149;

    strcpy((char*)ptr + strlen(nika) + 2 + strlen(luka) + 2, kosta);
    *((unsigned char*)((char*)ptr + strlen(nika) + 2 + strlen(luka) + 2 + strlen(kosta) + 1)) = 150;
    
    *((char*)ptr + strlen(nika) + 2 + strlen(luka) + 2 + strlen(kosta) + 2) = '\0';
    
    char** result = GoodStudents(ptr);

    return result != NULL && strcmp(result[0], nika) == 0 && strcmp(result[1], kosta) == 0;
}


int main(){
  Test("Test1 ", test1);
  return 0;
}