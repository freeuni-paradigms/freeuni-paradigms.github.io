#include "my_memcpy.h"


void MyMemcpy(void * to, void * from, size_t elem_size){
  char * source = (char *)from;
  char * destination = (char *)to;
  for(int i = 0 ; i < elem_size ; i++){
    destination[i] = source[i];
  }
}
