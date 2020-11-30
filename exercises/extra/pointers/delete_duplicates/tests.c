#include "delete_duplicates.h"


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


bool TestTextWithoutDuplicates(){
  char * text = strdup("abcdefg");
  DeleteDuplicates(text);
  char * solution = strdup("abcdefg");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}

bool TestEmptyString(){
  char * text = strdup("");
  DeleteDuplicates(text);
  char * solution = strdup("");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}

bool TestTextsLengthIsOne(){
  char * text = strdup("a");
  DeleteDuplicates(text);
  char * solution = strdup("a");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}


bool TestTextContainsSameCharacters(){
  char * text = strdup("aaaaaaaaaaaaa");
  DeleteDuplicates(text);
  char * solution = strdup("a");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}

bool TestTextContainsDuplicateCharacters1(){
  char * text = strdup("abcdabcd");
  DeleteDuplicates(text);
  char * solution = strdup("abcd");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}

bool TestTextContainsDuplicateCharacters2(){
  char * text = strdup("abcaaabklc");
  DeleteDuplicates(text);
  char * solution = strdup("abckl");
  if(strcmp(text, solution) == 0){
    free(solution);
    return true;
  }
  free(solution);
  return false;
}


int main(){
  Test("Test text without duplicates.", TestTextWithoutDuplicates);
  Test("Test empty string.", TestEmptyString);
  Test("Test text's length is one.", TestTextsLengthIsOne);
  Test("Test text contains same characters.", TestTextContainsSameCharacters);
  Test("Test text contains duplicate characters.", TestTextContainsDuplicateCharacters1);
  Test("Test text contains duplicate characters.", TestTextContainsDuplicateCharacters2);
  return 0;
}
