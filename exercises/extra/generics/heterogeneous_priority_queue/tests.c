#include "heterogeneous_priority_queue.h"

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
  PQueueNew(&p, NULL);
  PQueueDispose(&p);
  return true;
}

//ints

bool CheckInts(PQueue * p){
  for(int i = 0; i < 10; i++){
    void * elem = PQueuePop(p);
    if(*((int *)elem) != i){
      free(elem);
      PQueueDispose(p);
      return false;
    }
    free(elem);
  }
  PQueueDispose(p);
  return true;
}

bool TestPushAndPopInts(){
  PQueue p;
  PQueueNew(&p, NULL);
  for(int i = 0 ; i < 10; i++){
    PQueuePush(&p, &i, sizeof(int), i);
  }
  return CheckInts(&p);
}

//c_strings

void StrFree(void* ptr) {
  free(*(char**)ptr);
}

bool CheckStrings(PQueue * p){
  void * elem = PQueuePop(p);
  if(strcmp(*((char **)elem), "a") != 0 ){
    StrFree(elem);
    free(elem);
    PQueueDispose(p);
    return false;
  }
  StrFree(elem);
  free(elem);
  elem = PQueuePop(p);
  if(strcmp(*((char **)elem), "b") != 0 ){
    StrFree(elem);
    free(elem);
    PQueueDispose(p);
    return false;
  }
  StrFree(elem);
  free(elem);
  elem = PQueuePop(p);
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

bool TestPushAndPopOrderedStrings(){
  PQueue p;
  PQueueNew(&p, StrFree);
  char * str = strdup("a");
  PQueuePush(&p, &str, sizeof(char *), 2);
  str = strdup("b");
  PQueuePush(&p, &str, sizeof(char *), 4);
  str = strdup("c");
  PQueuePush(&p, &str, sizeof(char *), 5);
  return CheckStrings(&p);
}

//Pairs

typedef struct {
  int a;
  int b;
} Pair;

Pair NewPair(int a, int b) {
  Pair p;
  p.a = a;
  p.b = b;
  return p;
}

int ComparePair(void * a, void * b) {
  Pair p1 = *((Pair *)a);
  Pair p2 = *((Pair *)b);
  if (p1.a != p2.a) {
    return p1.a - p2.a;
  }
  return p1.b - p2.b;
}

bool CheckPairs(PQueue * p){
  for(int i = 0; i < 10; i++){
    void * elem = PQueuePop(p);
    Pair pair = NewPair(i, i);
    if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(p);
      return false;
    }
    free(elem);
  }
  PQueueDispose(p);
  return true;
}

bool TestPushAndPopOrderedPairs(){
  PQueue p;
  PQueueNew(&p, NULL);
  for(int i = 0; i < 10; i++){
    Pair pair = NewPair(i, i);
    PQueuePush(&p, &pair, sizeof(Pair), i);
  }
  return CheckPairs(&p);
}

//Different types.

bool TestPushAndPopDifferentTypes(){
  PQueue p;
  PQueueNew(&p, NULL);
  char c = 'a';
  PQueuePush(&p, &c, sizeof(char), 2);
  Pair pair = NewPair(4, 5);
  PQueuePush(&p, &pair, sizeof(Pair), 3);
  float n = 12.5;
  PQueuePush(&p, &n, sizeof(float), 4);
  void * elem = PQueuePop(&p);
  if(*(char *)elem != 'a'){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(*(float *)elem != 12.5){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopUnorderedDifferentTypes(){
  PQueue p;
  PQueueNew(&p, NULL);
  char c = 'a';
  PQueuePush(&p, &c, sizeof(char), 4);
  Pair pair = NewPair(4, 5);
  PQueuePush(&p, &pair, sizeof(Pair), 3);
  short n = 12;
  PQueuePush(&p, &n, sizeof(short), 2);
  void * elem = PQueuePop(&p);
  if(*(short *)elem != 12){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(*(char *)elem != 'a'){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopUnorderedDifferentTypes2(){
  PQueue p;
  PQueueNew(&p, NULL);
  char c = 'a';
  PQueuePush(&p, &c, sizeof(char), 1);
  float n = 12.5;
  PQueuePush(&p, &n, sizeof(float), 3);
  char * str = "abc";
  PQueuePush(&p, &str, sizeof(char *), 2);
  void * elem = PQueuePop(&p);
  if(*(char *)elem != 'a'){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(strcmp(str, *((char **)elem)) != 0){
      free(elem);
      PQueueDispose(&p);
      return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(*(float *)elem != 12.5){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopUnorderedDifferentTypesWithSamePriorities(){
  PQueue p;
  PQueueNew(&p, NULL);
  int k = 0;
  PQueuePush(&p, &k, sizeof(int), 1);
  float n = -12.5;
  PQueuePush(&p, &n, sizeof(float), 1);
  Pair pair = NewPair(4, 5);
  PQueuePush(&p, &pair, sizeof(Pair), 1);
  void * elem = PQueuePop(&p);
  if(*(int *)elem != 0){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(*(float *)elem != -12.5){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  elem = PQueuePop(&p);
  if(ComparePair(&pair, elem) != 0){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

int main(){
  Test("Test empty priority queue.", TestEmptyQueue);
  Test("Test push and pop ints.", TestPushAndPopInts);
  Test("Test push and pop ordered strings.", TestPushAndPopOrderedStrings);
  Test("Test push and pop ordered Pairs.", TestPushAndPopOrderedPairs);
  Test("Test push and pop different types.", TestPushAndPopDifferentTypes);
  Test("Test push and pop unordered different types.",  TestPushAndPopUnorderedDifferentTypes);
  Test("Test push and pop unordered different types.",  TestPushAndPopUnorderedDifferentTypes2);
  Test("Test push and pop unordered different types with same priorities", TestPushAndPopUnorderedDifferentTypesWithSamePriorities);
  return 0;
}
