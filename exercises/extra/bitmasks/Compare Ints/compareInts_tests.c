#include "compareInts.h"
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

bool testPositiveNumbers(){
	for(int i = 1 ; i < 1000; i++){
		if(compareInts(i, i+1) != (i+1))return false;
		if(compareInts(i+1, i) != (i+1))return false;
	}
  return true;
}

bool testEqualNumbers(){
	for(int i= 0 ; i < 1000; i++){
		if(compareInts(i , i) != i) return false;
	}
	return true;
}

bool testNegativeNumbers(){
	for(int i = -1 ; i <-1000; i--){
		if(compareInts(i, i-1) != i) return false;
		if(compareInts(i-1, i) != i) return false;
	}
	return true;
}

bool testPositiveAndNegativeNumbers(){
	for(int i = 0; i < 1000; i++){
		if(compareInts(i, -i) != i) return false;
		if(compareInts(-i, i) != i) return false;
	}
	return true;
}

int main(){
  Test("Test positive numbers.", testPositiveNumbers);
  Test("Test equal numbers.", testEqualNumbers);
  Test("Test negative numbers.", testNegativeNumbers);
  Test("Test positive and negative numbers.", testPositiveAndNegativeNumbers);
  return 0;
}
