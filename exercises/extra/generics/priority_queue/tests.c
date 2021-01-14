#include "solution.h"

#include <stdbool.h>

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

int CompareInts(void * a , void * b){
  int * p1 = (int*)a;
  int * p2 = (int *)b;
  return *p1 - *p2;
}

int CompareStrings(void * a , void * b){
  char * p1 = *(char**)a;
  char * p2 = *(char**)b;
  return strcmp(p1 , p2);
}

bool TestEmptyQueue(){
  PQueue p;
  PQueueNew(&p, 0, NULL, CompareInts);
  PQueueDispose(&p);
  return true;
}

bool CheckInts(PQueue * p){
  void * elem = malloc(sizeof(int));
  for(int i = 0; i < 10; i++){
    PQueuePop(p, elem);
    if(*((int *)elem) != i){
      free(elem);
      PQueueDispose(p);
      return false;
    }
  }
  free(elem);
  PQueueDispose(p);
  return true;
}

bool TestPushAndPopInts(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 0; i < 10; i++){
    PQueuePush(&p, &i);
  }
  return CheckInts(&p);
}

bool TestPushAndPopInts2(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 9; i >= 0; i--){
    PQueuePush(&p, &i);
  }
  return CheckInts(&p);
}

bool TestPushAndPopInts3(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 9; i >= 0; i--){
    if(i % 2 == 1){
      PQueuePush(&p, &i);
    }
  }
  for(int i = 9; i >= 0; i--){
    if(i % 2 == 0){
      PQueuePush(&p, &i);
    }
  }
  return CheckInts(&p);
}

bool TestPushAndPopIntsWithDuplicates(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 0; i < 10; i++){
    PQueuePush(&p, &i);
    PQueuePush(&p, &i);
  }
  void * elem = malloc(sizeof(int));
  for(int i = 0; i < 10; i++){
    PQueuePop(&p, elem);
    if(*((int *)elem) != i){
      free(elem);
      PQueueDispose(&p);
      return false;
    }
    PQueuePop(&p, elem);
    if(*((int *)elem) != i){
      free(elem);
      PQueueDispose(&p);
      return false;
    }
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

void StrFree(void* ptr) {
  free(*(char**)ptr);
}

bool CheckStrings(PQueue * p){
  void * elem = malloc(sizeof(char *));
  PQueuePop(p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
    StrFree(elem);
    free(elem);
    PQueueDispose(p);
    return false;
  }
  StrFree(elem);
  PQueuePop(p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
    StrFree(elem);
    free(elem);
    PQueueDispose(p);
    return false;
  }
  StrFree(elem);
  PQueuePop(p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
    StrFree(elem);
    free(elem);
    PQueueDispose(p);
    return false;
  }
  StrFree(elem);
  free(elem);
  PQueueDispose(p);
  return true;
}

bool TestPushAndPopStrings(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree, CompareStrings);
  char * str = strdup("a");
  PQueuePush(&p, &str);
  str = strdup("b");
  PQueuePush(&p, &str);
  str = strdup("c");
  PQueuePush(&p, &str);
  return CheckStrings(&p);
}

bool TestPushAndPopStrings2(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree, CompareStrings);
  char * str = strdup("c");
  PQueuePush(&p, &str);
  str = strdup("b");
  PQueuePush(&p, &str);
  str = strdup("a");
  PQueuePush(&p, &str);
  return CheckStrings(&p);
}

bool TestPushAndPopStrings3(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree, CompareStrings);
  char * str = strdup("a");
  PQueuePush(&p, &str);
  str = strdup("c");
  PQueuePush(&p, &str);
  str = strdup("b");
  PQueuePush(&p, &str);
  return CheckStrings(&p);
}

bool TestPushAndPopStringsWithDuplicates(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree, CompareStrings);
  char * str = strdup("a");
  char * str2 = strdup("a");
  PQueuePush(&p, &str);
  PQueuePush(&p, &str2);
  str = strdup("b");
  str2 = strdup("b");
  PQueuePush(&p, &str);
  PQueuePush(&p, &str2);
  str = strdup("c");
  str2 = strdup("c");
  PQueuePush(&p, &str);
  PQueuePush(&p, &str2);
  void * elem = malloc(sizeof(char *));
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      StrFree(elem);
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  StrFree(elem);
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      StrFree(elem);
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  StrFree(elem);
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
     StrFree(elem);
     free(elem);
     PQueueDispose(&p);
     return false;
  }
  StrFree(elem);
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      StrFree(elem);
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  StrFree(elem);
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      StrFree(elem);
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  StrFree(elem);
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      StrFree(elem);
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  StrFree(elem);
  free(elem);
  PQueueDispose(&p);
  return true;
}


int main(){
  Test("Test empty priority queue.", TestEmptyQueue);
  Test("Test push and pop ints.", TestPushAndPopInts);
  Test("Test push and pop ints.", TestPushAndPopInts2);
  Test("Test push and pop ints.", TestPushAndPopInts3);
  Test("Test push and pop ints with duplicates.", TestPushAndPopIntsWithDuplicates);
  Test("Test push and pop strings", TestPushAndPopStrings);
  Test("Test push and pop strings", TestPushAndPopStrings2);
  Test("Test push and pop strings", TestPushAndPopStrings3);
  Test("Test push and pop strings with duplicates.", TestPushAndPopStringsWithDuplicates);
  return 0;
}
