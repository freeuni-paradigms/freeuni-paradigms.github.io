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

bool TestPushAndPopOrderedInts(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 0; i < 10; i++){
    PQueuePush(&p, &i);
  }
  return CheckInts(&p);
}

bool TestPushAndPopUnorderedInts(){
  PQueue p;
  PQueueNew(&p, sizeof(int), NULL, CompareInts);
  for(int i = 9; i >= 0; i--){
    PQueuePush(&p, &i);
  }
  return CheckInts(&p);
}

bool TestPushAndPopUnorderedInts2(){
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

bool TestPushAndPopOrderedStrings(){
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

bool TestPushAndPopUnorderedStrings(){
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

bool TestPushAndPopUnorderedStrings2(){
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

bool CheckPairs(PQueue * p){
  void * elem = malloc(sizeof(Pair));
  for(int i = 0; i < 10; i++){
    PQueuePop(p, elem);
    Pair pair = NewPair(i, i);
    if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(p);
      return false;
    }
  }
  free(elem);
  PQueueDispose(p);
  return true;
}

bool TestPushAndPopOrderedPairs(){
  PQueue p;
  PQueueNew(&p, sizeof(Pair), NULL, ComparePair);
  for(int i = 0; i < 10; i++){
    Pair pair = NewPair(i, i);
    PQueuePush(&p, &pair);
  }
  return CheckPairs(&p);
}

bool TestPushAndPopUnorderedPairs(){
  PQueue p;
  PQueueNew(&p, sizeof(Pair), NULL, ComparePair);
  for(int i = 9; i >= 0; i--){
    Pair pair = NewPair(i, i);
    PQueuePush(&p, &pair);
  }
  return CheckPairs(&p);
}

bool TestPushAndPopUnorderedPairs2(){
  PQueue p;
  PQueueNew(&p, sizeof(Pair), NULL, ComparePair);
  for(int i = 0; i < 10; i++){
    if(i % 2 == 1){
      Pair pair = NewPair(i, i);
      PQueuePush(&p, &pair);
    }
  }
  for(int i = 0; i < 10; i++){
    if(i % 2 == 0){
      Pair pair = NewPair(i, i);
      PQueuePush(&p, &pair);
    }
  }
  return CheckPairs(&p);
}

bool TestPushAndPopPairsWithDuplicates(){
  PQueue p;
  PQueueNew(&p, sizeof(Pair), NULL, ComparePair);
  for(int i = 0; i < 10; i++){
    Pair pair = NewPair(i, i);
    PQueuePush(&p, &pair);
    PQueuePush(&p, &pair);
  }
  void * elem = malloc(sizeof(Pair));
  for(int i = 0; i < 10; i++){
    PQueuePop(&p, elem);
    Pair pair = NewPair(i, i);
    if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(&p);
      return false;
    }
    PQueuePop(&p, elem);
    if(ComparePair(&pair, elem) != 0){
      free(elem);
      PQueueDispose(&p);
      return false;
    }
  }
  free(elem);
  PQueueDispose(&p);
  return true;
}

bool TestPushAndPopPairsWithDifferentValues(){
  PQueue p;
  PQueueNew(&p, sizeof(Pair), NULL, ComparePair);
  Pair pair = NewPair(1, 2);
  PQueuePush(&p, &pair);
  pair = NewPair(2, 3);
  PQueuePush(&p, &pair);
  pair = NewPair(1, 3);
  PQueuePush(&p, &pair);
  void * elem = malloc(sizeof(Pair));
  PQueuePop(&p, elem);
  pair = NewPair(1, 2);
  if(ComparePair(&pair, elem) != 0){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  pair = NewPair(1, 3);
  PQueuePop(&p, elem);
  if(ComparePair(&pair, elem) != 0){
    free(elem);
    PQueueDispose(&p);
    return false;
  }
  pair = NewPair(2, 3);
  PQueuePop(&p, elem);
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
  Test("Test push and pop ordered ints.", TestPushAndPopOrderedInts);
  Test("Test push and pop unordered ints.", TestPushAndPopUnorderedInts);
  Test("Test push and pop unordered ints 2.", TestPushAndPopUnorderedInts2);
  Test("Test push and pop ints with duplicates.", TestPushAndPopIntsWithDuplicates);
  Test("Test push and pop ordered strings.", TestPushAndPopOrderedStrings);
  Test("Test push and pop unordered strings.", TestPushAndPopUnorderedStrings);
  Test("Test push and pop unordered strings 2.", TestPushAndPopUnorderedStrings2);
  Test("Test push and pop strings with duplicates.", TestPushAndPopStringsWithDuplicates);
  Test("Test push and pop ordered pairs.", TestPushAndPopOrderedPairs);
  Test("Test push and pop unordered pairs.", TestPushAndPopUnorderedPairs);
  Test("Test push and pop unordered pairs 2.", TestPushAndPopUnorderedPairs2);
  Test("Test push and pop pairs with duplicates.", TestPushAndPopPairsWithDuplicates);
  Test("Test push and pop pairs with different values.", TestPushAndPopPairsWithDifferentValues);
  return 0;
}
