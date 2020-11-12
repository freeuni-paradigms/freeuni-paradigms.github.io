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

bool TestZero(){
  for(int i = 0 ; i < 32; i++){
    if(setZero(0, i) != 0) return false;
  }
  return true;
}


bool TestStaysTheSame(){
  int n = 1;
  for(int i = 0; i < 32; i++){
    if(setZero(n, i) != n) return false;
    n = n * 2;
  }
  return true;
}

bool TestPositiveNumbers1(){
  int n = 1;
  for(int i = 0; i < 32; i++){
    if(setZero(n, 31 - i) != 0) return false;
    n = n * 2;
  }
  return true;
}

bool TestPositiveNumbers2(){
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

bool TestNegativeNumbers1(){
  unsigned int mask = 1;
  mask = mask << 31;
  if(setZero(mask, 0) != 0) return false;
  return true;
}


bool TestNegativeNumbers2(){
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
  Test("Test number is zero.", TestZero);
  Test("Test number stays the same.", TestStaysTheSame);
  Test("Test number becomes zero.", TestPositiveNumbers1);
  Test("Change positive number.", TestPositiveNumbers2);
  Test("Make sign bit zero.", TestNegativeNumbers1);
  Test("Change negative number.", TestNegativeNumbers2); 
  return 0;
}
