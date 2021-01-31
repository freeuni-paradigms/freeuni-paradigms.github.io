#include "solution.h"

void PQueueNew(PQueue * p, void (*free_fn)(void *)){
  p->log_len = 0;
  p->bytes_size = 0;
  p->free_fn = free_fn;
  p->elems = malloc(0);
  assert(p->elems != NULL);
  p->priorities = (int *)malloc(0);
  assert(p->priorities != NULL);
  p->bytes = (int *)malloc(sizeof(int));
  assert(p->bytes != NULL);
  p->bytes[0] = 0; //offset of the first element.
}

void UpdateBytesArray(PQueue * p, int elem_size, int i){
   memmove(p->bytes + i + 2, p->bytes + i + 1, (p->log_len - i) * 4);
   p->bytes[i+1] = p->bytes[i] + elem_size;
   for(int j = i + 2; j <= p->log_len + 1; j++){
     p->bytes[j] = p->bytes[j] + elem_size;
   }
}

void PQueuePush(PQueue * p, void * elem, int elem_size, int priority){
  p->elems = realloc(p->elems, p->bytes_size + elem_size);
  assert(p->elems != NULL);
  p->priorities = (int *)realloc(p->priorities, (p->log_len + 1) * sizeof(int));
  assert(p->priorities != NULL);
  p->bytes = (int *)realloc(p->bytes, (p->log_len + 2) * sizeof(int));
  assert(p->bytes != NULL);
  for(int i = 0; i < p->log_len; i++){
    if(p->priorities[i] > priority){
      memmove((char *)p->elems + p->bytes[i] + elem_size, (char *)p->elems + p->bytes[i], p->bytes_size - p->bytes[i]);
      memcpy((char *)p->elems + p->bytes[i], elem, elem_size);
      UpdateBytesArray(p, elem_size, i);
      memmove(p->priorities + i + 1, p->priorities + i, (p->log_len - i) * 4);
      p->priorities[i] = priority;
      p->log_len++;
      p->bytes_size += elem_size;
      return;
    }
  }
  //Push elem in the end.
  p->priorities[p->log_len] = priority;
  memcpy((char *)p->elems + p->bytes[p->log_len], elem , elem_size);
  p->bytes[p->log_len + 1] = p->bytes[p->log_len] + elem_size;
  p->log_len++;
  p->bytes_size += elem_size;
}

void * PQueuePop(PQueue * p){
  assert(p->log_len != 0);
  int elem_size = p->bytes[1];
  void * elem = malloc(elem_size);
  assert(elem != NULL);
  memcpy(elem, p->elems, elem_size);
  if(p->log_len > 1){
    memmove(p->elems, (char *)p->elems + elem_size, p->bytes_size - elem_size);
    memmove(p->priorities, p->priorities + 1, (p->log_len - 1) * 4);
    for(int i = 2; i <= p->log_len; i++){
      p->bytes[i] -= elem_size;
    }
    memmove(p->bytes+1, p->bytes + 2, (p->log_len-1) * 4);
  }
  p->log_len--;
  p->bytes_size -= elem_size;
  return elem;
}

void PQueueDispose(PQueue * p){
  if(p->free_fn != NULL){
    for(int i = 0 ; i < p->log_len; i++){
      p->free_fn((char *)p->elems + i * p->bytes[i]);
    }
  }
  free(p->elems);
  free(p->priorities);
  free(p->bytes);
}

