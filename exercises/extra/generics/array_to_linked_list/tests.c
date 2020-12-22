#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "linked_array_list.h"


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

bool Test1(){
  LAL lal;
  LALInit(&lal, NULL, sizeof(int), 0, NULL);
  ASSERT(LALSize(&lal) == 0);

  for(int i = 0; i < 10; i++)
    LALAppend(&lal, &i);

  ASSERT(LALSize(&lal) == 10)
  
  for(int i = 0; i < 10; i++)
    ASSERT(*((int*)LALGet(&lal, i)) == i)

  for (int i = 0; i < 5; i++)
    LALRemove(&lal, 0);
  
  ASSERT(LALSize(&lal) == 5);

  for(int i = 0; i < 5; i++)
    ASSERT(*((int*)LALGet(&lal, i)) == i + 5)

  for (int i = 4; i >= 0; i--)
    LALRemove(&lal, i);
  
  ASSERT(LALSize(&lal) == 0);

  return true;
}

void FreeString(void* elem_address){
  free(*((char**)elem_address));
}

bool Test2(){
  LAL lal;
  LALInit(&lal, NULL, sizeof(int), 0, FreeString);
  
  char* str = strdup("George");
  LALAppend(&lal, &str);

  str = strdup("12345678");
  LALAppend(&lal, &str);

  str = strdup("abcdefg");
  LALAppend(&lal, &str);
  
  str = strdup("");;
  LALAppend(&lal, &str);

  ASSERT(LALSize(&lal) == 4 
  && strcmp(*((char**)LALGet(&lal, 0)) , "George") == 0 
  && strcmp(*((char**)LALGet(&lal, 1)) , "12345678") == 0 
  && strcmp(*((char**)LALGet(&lal, 2)) , "abcdefg") == 0
  && strcmp(*((char**)LALGet(&lal, 3)) , "") == 0);

  LALRemove(&lal, 2);

  ASSERT(LALSize(&lal) == 3 && strcmp(*((char**)LALGet(&lal, 2)) , "") == 0);

  return true;
}

bool Test3(){
  LAL lal;
  int arr[50];
  for (int i = 0; i < 50; i++)
    arr[i] = i;    
  
  LALInit(&lal, arr, sizeof(int), 50, NULL);
  
  ASSERT(LALSize(&lal) == 50);

  for (int i = 0; i < 50; i++)
    ASSERT(*((int*)LALGet(&lal, i)) == i);

  LALAppendArray(&lal, arr + 10, 40);

  for (int i = 50; i < 90; i++)
    ASSERT(*((int*)LALGet(&lal, i )) == i - 40);  

  return true;
}

bool Test4(){
  LAL lal;
  char* alphabet = "abcdefghijklmnopqrstuvwxyz";
  LALInit(&lal, alphabet, sizeof(char), 26, NULL);

  ASSERT(LALSize(&lal) == 26);

  ASSERT(strncmp((char*)LALGetInterval(&lal, 0, 2), "abc", 3) == 0);

  ASSERT(strncmp((char*)LALGetInterval(&lal, 5, 5), "f", 1) == 0);

  ASSERT(strncmp((char*)LALGetInterval(&lal, 0, 25), alphabet, 26) == 0);

  char* digits = "0123456789";
  LALAppendArray(&lal, digits, 10);

  ASSERT(LALSize(&lal) == 36);

  ASSERT(strncmp((char*)LALGetInterval(&lal, 26, 35), digits, 10) == 0);

  return true;
}

int main(){
  Test("Testing without array functions and FreeFunction", Test1);
  Test("Testing on char* with FreeFunction and without array functions", Test2);
  Test("Testing constructor with passed array and LALAppendArray", Test3);
  Test("Testing get LALGetInterval function", Test4);
  return 0;
}
