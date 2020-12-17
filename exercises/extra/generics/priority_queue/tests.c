#include "priority_queue.h"

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

bool TestEmptyQueue(){
  PQueue p;
  PQueueNew(&p, 0, NULL);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopInts(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL);
  for(int i = 0 ; i < 10; i++){
    PQueuePush(&p, &i, i);
  }
  void * elem = malloc(sizeof(int));
  for(int i = 0 ; i < 10; i++){
    PQueuePop(&p, elem);
    if(*((int *)elem) != i){
      return false;
    }
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopInts2(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL);
  for(int i = 0 ; i < 10; i++){
    PQueuePush(&p, &i, 10 - i);
  }
  void * elem = malloc(sizeof(int));
  for(int i = 0 ; i < 10; i++){
    PQueuePop(&p, elem);
    if(*((int *)elem) != (9 - i)){
      return false;
    }
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopInts3(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL);
  for(int i = 0 ; i < 10; i++){
    if(i % 2 == 1){
      PQueuePush(&p, &i, 10 - i);
    }
  }
  for(int i = 0 ; i < 10; i++){
    if(i % 2 == 0){
      PQueuePush(&p, &i, 10 - i);
    }
  }
  void * elem = malloc(sizeof(int));
  for(int i = 0 ; i < 10; i++){
    PQueuePop(&p, elem);
    if(*((int *)elem) != (9 - i)){
      return false;
    }
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopIntsWithDuplicates(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL);
  for(int i = 0 ; i < 10; i++){
    PQueuePush(&p, &i, i);
    PQueuePush(&p, &i, i);
  }
  void * elem = malloc(sizeof(int));
  for(int i = 0 ; i < 10; i++){
    PQueuePop(&p, elem);
    if(*((int *)elem) != i){
      return false;
    }
    PQueuePop(&p, elem);
    if(*((int *)elem) != i){
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

bool TestPushAndPopStrings(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree);
  char * str = strdup("a");
  PQueuePush(&p, &str, 1);
  str = strdup("b");
  PQueuePush(&p, &str, 3);
  str = strdup("c");
  PQueuePush(&p, &str, 8);
  void * elem = malloc(sizeof(char *));
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopStrings2(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree);
  char * str = strdup("a");
  PQueuePush(&p, &str, 8);
  str = strdup("b");
  PQueuePush(&p, &str, 3);
  str = strdup("c");
  PQueuePush(&p, &str, 1);
  void * elem = malloc(sizeof(char *));
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopStrings3(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree);
  char * str = strdup("a");
  PQueuePush(&p, &str, 1);
  str = strdup("b");
  PQueuePush(&p, &str, 5);
  str = strdup("c");
  PQueuePush(&p, &str, 2);
  void * elem = malloc(sizeof(char *));
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopStringsWithDuplicates(){
  PQueue p;
  PQueueNew(&p, sizeof(char *), StrFree);
  char * str = strdup("a");
  PQueuePush(&p, &str, 1);
  PQueuePush(&p, &str, 1);
  str = strdup("b");
  PQueuePush(&p, &str, 2);
  PQueuePush(&p, &str, 2);
  str = strdup("c");
  PQueuePush(&p, &str, 3);
  PQueuePush(&p, &str, 3);
  void * elem = malloc(sizeof(char *));
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "a") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "b") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      return false;
  }
  PQueuePop(&p, elem);
  if(strcmp(*((char **)elem), "c") != 0 ){
      return false;
  }
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
