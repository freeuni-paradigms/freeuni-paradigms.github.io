#include "my_memcpy.h"


void MyMemcpy(void * to, void * from, size_t elemSize){
  char * temp = (char *)from;
  char * temp2 = (char *)to;
  for(int i = 0 ; i < elemSize ; i++){
    temp2[i] = temp[i];
  }
}
