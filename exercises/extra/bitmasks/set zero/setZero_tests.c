#include "setZero.h"
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

bool testZero(){
  for(int i = 0 ; i < 32; i++){
    if(setZero(0, i) != 0) return false;
  }
  return true;
}


bool testStaysTheSame(){
  int n = 1;
  for(int i = 0; i < 32; i++){
    if(setZero(n, i) != n) return false;
    n = n * 2;
  }
  return true;
}

bool testPositiveNumbers1(){
  int n = 1;
  for(int i = 0; i < 32; i++){
    if(setZero(n, 31 - i) != 0) return false;
    n = n * 2;
  }
  return true;
}

bool testPositiveNumbers2(){
  unsigned int mask = 1;
  mask = mask << 31;
  mask = mask - 1;
  int n = 1;
  for(int i = 0 ; i < 31; i++){
    if(setZero(mask, 31- i) != mask - n) return false;
    n = n * 2;
  }
  return true;
}

bool testNegativeNumbers1(){
  unsigned int mask = 1;
  mask = mask << 31;
  int n = mask - 1;
  if(setZero(mask, 0) != 0) return false;
  return true;
}


bool testNegativeNumbers2(){
  unsigned int mask = 1;
  mask = mask << 31;
  mask = mask - 1;
  mask = mask << 1;
  mask = mask + 1;
  int n = 1;
  for(int i = 0 ; i < 31; i++){
    if(setZero(mask, 31- i) != mask - n) return false;
    n = n * 2;
  }
  return true;
}


int main(){
  Test("Test number is zero.", testZero);
  Test("Test number stays the same.", testStaysTheSame);
  Test("Test number becomes zero.", testPositiveNumbers1);
  Test("Change positive number.", testPositiveNumbers2);
  Test("Make sign bit zero.", testNegativeNumbers1);
  Test("Change negative number.", testNegativeNumbers2); 
  return 0;
}
