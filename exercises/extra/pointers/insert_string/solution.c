#include "insert_string.h"

char *InsertString(char *str1, int index, char *str2){
  int size = strlen(str1) + strlen(str2) + 1;
  char *res = malloc(size);
  strncpy(res, str1, index);
  strncpy(res + index, str2, strlen(str2));
  strncpy(res + index + strlen(str2), str1 + index, strlen(str1) - index);
  res[size - 1] = '\0';
  return res;
}
