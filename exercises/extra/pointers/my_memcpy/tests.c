#include "my_memcpy.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}


bool TestMemcpyChars(){
  char a = 'a';
  char b = 'b';
  MyMemcpy(&a, &b, sizeof(char));
  if(a == b){
    return true;
  }
  return false;
}


bool TestMemcpyShorts(){
  short a = 0;
  short b = 0;
  for(short i = 0; i < 100; i++){
    a = i;
    b = i+1;
    MyMemcpy(&a, &b, sizeof(short));
    if(a != b) return false;
  }
  return true;
}

bool TestMemcpyInts(){
  int a = 0;
  int b = 0;
  for(int i = 0; i < 100; i++){
    a = i;
    b = i+1;
    MyMemcpy(&a, &b, sizeof(int));
    if(a != b) return false;
  }
  return true;
}


bool TestMemcpyFloats(){
  float a = 0.0;
  float b = 0.0;
  for(float i = 0.0; i < 100; i++){
    a = i;
    b = i + 0.5;
    MyMemcpy(&a, &b, sizeof(float));
    if(a != b) return false;
  }
  return true;
}

bool TestMemcpyStrings(){
  char * a = strdup("my_memcpy1");
  char * b = strdup("my_memcpy2");
  MyMemcpy(a, b, strlen(b) + 1);
  if(strcmp(a, b) == 0){
    free(a);
    free(b);
    return true;
  }
  free(a);
  free(b);
  return false;
}


bool TestMemcpyPointers(){
  int a = 0;
  int b = 0;
  for(int i = 0; i < 100; i++){
    a = i;
    b = i+1;
    int * a2 = &a;
    int * b2 = &b;
    MyMemcpy(&a2, &b2, sizeof(int *));
    if(memcmp(&a2 , &b2, sizeof(int *)) != 0){
      return false;
    }
  }
  return true;
}

bool TestMemcpyPointers2(){
  float a = 0.0;
  float b = 0.0;
  for(float i = 0.0; i < 100; i+=0.5){
    a = i;
    b = i+1;
    float * a2 = &a;
    float * b2 = &b;
    MyMemcpy(&a2, &b2, sizeof(float *));
    if(memcmp(&a2 , &b2, sizeof(float *)) != 0){
      return false;
    }
  }
  return true;
}


int main(){
  Test("Test memcpy chars.", TestMemcpyChars);
  Test("Test memcpy shorts.", TestMemcpyShorts);
  Test("Test memcpy ints.", TestMemcpyInts);
  Test("Test memcpy floats.", TestMemcpyFloats);
  Test("Test memcpy strings.", TestMemcpyStrings);
  Test("Test memcpy pointers",  TestMemcpyPointers);
  Test("Test memcpy pointers.", TestMemcpyPointers2);
  return 0;
}
