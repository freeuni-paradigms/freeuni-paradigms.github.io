#include "insertion_sort.h"

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

int CompareInts(void * a , void * b){
  int * p1 = (int*)a;
  int * p2 = (int *)b;
  return *p1 - *p2;
}

int CompareShorts(void * a , void * b){
  short * p1 = (short *)a;
  short * p2 = (short *)b;
  return *p1 - *p2;
}

int CompareFloats(void * a , void * b){
  float * p1 = (float *)a;
  float * p2 = (float *)b;
  if((*p1 - *p2) < 0){
    return -1;
  }else if((*p1 - *p2) > 0){
    return 1;
  }
  return 0;
}

int CompareChars(void * a , void * b){
  char * p1 = (char *)a;
  char * p2 = (char *)b;
  return *p1 - *p2;
}

int CompareStrings(void * a , void * b){
  char * p1 = *(char**)a;
  char * p2 = *(char**)b;
  return strcmp(p1 , p2);
}

bool TestSortChars(){
  char elems[5] = {'c', 'a', 'd', 'b', 'e'};
  char solution[5] = {'a', 'b', 'c', 'd', 'e'};
  InsertionSort(elems, 5, sizeof(char), CompareChars);
  if(memcmp(elems, solution, 5 * sizeof(char)) != 0){
    return false;
  }

  //Test array stays the same.
  char elems2[5] = {'a', 'b', 'c', 'd', 'e'};
  char solution2[5] = {'a', 'b', 'c', 'd', 'e'};
  InsertionSort(elems2, 5, sizeof(char), CompareChars);
  if(memcmp(elems2, solution2, 5 * sizeof(char)) != 0){
    return false;
  }

  //Test contains duplicates.
  char elems3[5] = {'c', 'a', 'a', 'b', 'e'};
  char solution3[5] = {'a', 'a', 'b', 'c', 'e'};
  InsertionSort(elems3, 5, sizeof(char), CompareChars);
  if(memcmp(elems3, solution3, 5 * sizeof(char)) != 0){
    return false;
  }
  return true;
}

bool TestSortShorts(){
  short elems[5] = {1, 5, 2, 3, 8};
  short solution[5] = {1, 2, 3, 5, 8};
  InsertionSort(elems, 5, sizeof(short), CompareShorts);
  if(memcmp(elems, solution, 5 * sizeof(short)) != 0){
    return false;
  }

  //Test array stays the same.
  short elems2[5] = {1, 2, 3, 4, 5};
  short solution2[5] = {1, 2, 3, 4, 5};
  InsertionSort(elems2, 5, sizeof(short), CompareShorts);
  if(memcmp(elems2, solution2, 5 * sizeof(short)) != 0){
    return false;
  }

  //Test contains duplicates.
  short elems3[5] = {1, 5, 2, 1, 8};
  short solution3[5] = {1, 1, 2, 5, 8};
  InsertionSort(elems3, 5, sizeof(short), CompareShorts);
  if(memcmp(elems3, solution3, 5 * sizeof(short)) != 0){
    return false;
  }
  return true;
}

bool TestSortInts(){
  int elems[5] = {1, 5, 2, 3, 8};
  int solution[5] = {1, 2, 3, 5, 8};
  InsertionSort(elems, 5, sizeof(int), CompareInts);
  if(memcmp(elems, solution, 5 * sizeof(int)) != 0){
    return false;
  }

  //Test array stays the same.
  int elems2[5] = {-1, 2, 3, 4, 5};
  int solution2[5] = {-1, 2, 3, 4, 5};
  InsertionSort(elems2, 5, sizeof(int), CompareInts);
  if(memcmp(elems2, solution2, 5 * sizeof(int)) != 0){
    return false;
  }

  //Test contains duplicates.
  int elems3[5] = {1, 5, 2, 1, 8};
  int solution3[5] = {1, 1, 2, 5, 8};
  InsertionSort(elems3, 5, sizeof(int), CompareInts);
  if(memcmp(elems3, solution3, 5 * sizeof(int)) != 0){
    return false;
  }
  return true;
}

bool TestSortFloats(){
  float elems[5] = {1.2, 5.4, 2.123, 3.1, 8.54};
  float solution[5] = {1.2, 2.123, 3.1, 5.4, 8.54};
  InsertionSort(elems, 5, sizeof(float), CompareFloats);
  if(memcmp(elems, solution, 5 * sizeof(float)) != 0){
    return false;
  }

  //Test array stays the same.
  float elems2[5] = {-1.1, 2.2, 3.3, 4.4, 5.5};
  float solution2[5] = {-1.1, 2.2, 3.3, 4.4, 5.5};
  InsertionSort(elems2, 5, sizeof(float), CompareFloats);
  if(memcmp(elems2, solution2, 5 * sizeof(float)) != 0){
    return false;
  }

  //Test contains duplicates.
  float elems3[5] = {0.2, 5.2, 5.2, 1.1, 0.2};
  float solution3[5] = {0.2, 0.2, 1.1, 5.2, 5.2};
  InsertionSort(elems3, 5, sizeof(float), CompareFloats);
  if(memcmp(elems3, solution3, 5 * sizeof(float)) != 0){
    return false;
  }
  return true;
}

bool TestSortStrings(){
  char * elems[5] = {"a", "c", "da", "ba", "o"};
  char * solution[5] = {"a", "ba", "c", "da", "o"};
  InsertionSort(elems, 5, sizeof(char *), CompareStrings);
  if(memcmp(elems, solution, 5 * sizeof(char *)) != 0){
    return false;
  }

  //Test array stays the same.
  char * elems2[5] = {"a", "ba", "c", "da", "o"};
  char * solution2[5] = {"a", "ba", "c", "da", "o"};
  InsertionSort(elems2, 5, sizeof(char *), CompareStrings);
  if(memcmp(elems2, solution2, 5 * sizeof(char *)) != 0){
    return false;
  }

  //Test contains duplicates.
  char * elems3[5] = {"a", "ba", "a", "da", "o"};
  char * solution3[5] = {"a", "a", "ba", "da", "o"};
  InsertionSort(elems3, 5, sizeof(char *), CompareStrings);
  if(memcmp(elems3, solution3, 5 * sizeof(char *)) != 0){
    return false;
  }
  return true;
}

int main(){
  Test("Test sort chars.", TestSortChars);
  Test("Test sort shorts.", TestSortShorts);
  Test("Test sort ints.", TestSortInts);
  Test("Test sort floats.", TestSortFloats);
  Test("Test sort strings.", TestSortStrings);
  return 0;
}
