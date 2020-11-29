#include "insert_string.h"

#include <stdbool.h>

void Test(char *name, bool (*test_fn)()){
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()){
    printf("-- TEST %s: SUCCEEDED\n", name);
  }
  else{
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

void FreeMemory(char *str1, char *str2, char *res, char *solution_res){
  free(str1);
  free(str2);
  free(res);
  free(solution_res);
}

bool TestIndexIsZero(){
  char *str1 = strdup("abcd");
  char *str2 = strdup("ab");
  char *res = strdup("ababcd");
  char *solution_res = InsertString(str1, 0, str2);
  if (strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

bool TestInsertIntoTheEmptyString(){
  char *str1 = strdup("");
  char *str2 = strdup("abc");
  char *res = strdup("abc");
  char *solution_res = InsertString(str1, 0, str2);
  if(strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

bool TestInsertEmptyString(){
  char *str1 = strdup("abcdefg");
  char *str2 = strdup("");
  char *res = strdup("abcdefg");
  char *solution_res = NULL;
  for (int i = 0; i < strlen(str1); i++){
    solution_res = InsertString(str1, i, str2);
    if (strcmp(solution_res, res) != 0){
      FreeMemory(str1, str2, res, solution_res);
      return false;
    }
    FreeMemory(str1, str2, res, solution_res);
  }
  return true;
}

bool TestBothStringsAreEmpty(){
  char *str1 = strdup("");
  char *str2 = strdup("");
  char *res = strdup("");
  char *solution_res = InsertString(str1, 0, str2);
  if (strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

bool TestLastIndex(){
  char *str1 = strdup("test1");
  char *str2 = strdup("test2");
  char *res = strdup("test1test2");
  char *solution_res = InsertString(str1, strlen(str1), str2);
  if (strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

bool TestMiddleIndex1(){
  char *str1 = strdup("test1");
  char *str2 = strdup("test2");
  char *res = strdup("tetest2st1");
  char *solution_res = InsertString(str1, 2, str2);
  if (strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

bool TestMiddleIndex2(){
  char *str1 = strdup("test1");
  char *str2 = strdup("test2");
  char *res = strdup("testtest21");
  char *solution_res = InsertString(str1, 4, str2);
  if (strcmp(solution_res, res) != 0){
    FreeMemory(str1, str2, res, solution_res);
    return false;
  }else{
    FreeMemory(str1, str2, res, solution_res);
    return true;
  }
}

int main()
{
  Test("Test index is zero.", TestIndexIsZero);
  Test("Test insert into the empty string.", TestInsertIntoTheEmptyString);
  Test("Test insert empty string.", TestInsertEmptyString);
  Test("Test both strings are empty.", TestBothStringsAreEmpty);
  Test("Test last index.", TestLastIndex);
  Test("Test middle index.", TestMiddleIndex1);
  Test("Test middle index.", TestMiddleIndex2);
  return 0;
}
