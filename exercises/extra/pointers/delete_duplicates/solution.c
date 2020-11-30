#include "delete_duplicates.h"


//Checks if the current character is already in result.
bool IsAlreadyInResult(char ch, char * result){
  for(int i = 0; i < strlen(result); i++){
    if(result[i] == ch){
      return true;
    }
  }
  return false;
}


void DeleteDuplicates(char * text){
  int size = 0;
  int index = 0;
  char * result = (char *)malloc((strlen(text) + 1) * sizeof(char));
  while(true){
    char ch = text[index];
    index++;
    if(ch == '\0'){
      result[size] = '\0';
      break;
    }
    if(!IsAlreadyInResult(ch, result)){
      result[size] = ch;
      size++;
    }
  }
  free(text);
  result = (char *)realloc(result, size * sizeof(char));
}
