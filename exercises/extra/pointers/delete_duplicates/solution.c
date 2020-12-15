#include "delete_duplicates.h"

//Checks if the current character is already in result.
bool IsAlreadyInResult(char ch, char * result, int size){
  for(int i = 0; i < size; i++){
    if(result[i] == ch){
      return true;
    }
  }
  return false;
}


void DeleteDuplicates(char ** text){
  int size = 0;
  int index = 0;
  char * text2 = *text;
  char * result = (char *)malloc((strlen(text2) + 1) * sizeof(char));
  while(true){
    char ch = text2[index];
    index++;
    if(ch == '\0'){
      result[size] = '\0';
      break;
    }
    if(!IsAlreadyInResult(ch, result, size)){
      result[size] = ch;
      size++;
    }
  }
  free(*text);
  *text = result;
}
