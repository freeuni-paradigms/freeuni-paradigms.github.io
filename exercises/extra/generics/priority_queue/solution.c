#include "solution.h"

void PQueueNew(PQueue * p, int elem_size, void (*freeFn)(void *)){
  p->elem_size = elem_size;
  p->log_len = 0;
  p->freeFn = freeFn;
  p->elems = malloc(0);
  assert(p->elems != NULL);
  p->priorities = (int *)malloc(0);
  assert(p->priorities != NULL);
}

void PQueuePush(PQueue * p, void * elem, int priority){
  p->elems = realloc(p->elems, (p->log_len + 1) * p->elem_size);
  assert(p->elems != NULL);
  p->priorities = (int *)realloc(p->priorities, (p->log_len + 1) * sizeof(int));
  assert(p->priorities != NULL);
  for(int i = 0; i < p->log_len; i++){
    if(p->priorities[i] > priority){
      memmove((char *)p->elems + (i + 1)* p->elem_size, (char *)p->elems + i * p->elem_size, (p->log_len - i) * p->elem_size);
      memcpy((char *)p->elems + i * p->elem_size, elem, p->elem_size);
      memmove(p->priorities + i + 1, p->priorities + i, (p->log_len - i) * 4);
      p->priorities[i] = priority;
      p->log_len++;
      return;
    }
  }
  //Push elem in the end.
  p->priorities[p->log_len] = priority;
  memcpy((char *)p->elems + p->log_len * p->elem_size , elem , p->elem_size);
  p->log_len++;
}

void PQueuePop(PQueue * p, void * elem){
  assert(p->log_len != 0);
  memcpy(elem, p->elems, p->elem_size);
  if(p->log_len > 1){
    memmove(p->elems, (char *)p->elems + p->elem_size, (p->log_len - 1) * p->elem_size);
    memmove(p->priorities, p->priorities + 1, (p->log_len - 1) * 4);
  }
  p->log_len--;
}

void PQueueDispose(PQueue * p){
  if(p->freeFn != NULL){
    for(int i = 0 ; i < p->log_len; i++){
      p->freeFn((char *)p->elems + i * p->elem_size);
    }
  }
  free(p->elems);
  free(p->priorities);
}
