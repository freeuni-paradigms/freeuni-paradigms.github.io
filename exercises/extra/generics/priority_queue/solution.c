#include "solution.h"

void PQueueNew(PQueue * p, int elem_size, void (*free_fn)(void *), int (*cmp)(void * , void *)){
  p->elem_size = elem_size;
  p->log_len = 0;
  p->free_fn = free_fn;
  p->cmp = cmp;
  p->elems = malloc(0);
  assert(p->elems != NULL);
}

void PQueuePush(PQueue * p, void * elem){
  p->elems = realloc(p->elems, (p->log_len + 1) * p->elem_size);
  assert(p->elems != NULL);
  for(int i = 0; i < p->log_len; i++){
    if(p->cmp((char *)p->elems + i * p->elem_size, elem) > 0){
      memmove((char *)p->elems + (i + 1)* p->elem_size, (char *)p->elems + i * p->elem_size, (p->log_len - i) * p->elem_size);
      memcpy((char *)p->elems + i * p->elem_size, elem, p->elem_size);
      p->log_len++;
      return;
    }
  }
  //Push elem in the end.
  memcpy((char *)p->elems + p->log_len * p->elem_size , elem , p->elem_size);
  p->log_len++;
}

void PQueuePop(PQueue * p, void * elem){
  assert(p->log_len != 0);
  memcpy(elem, p->elems, p->elem_size);
  if(p->log_len > 1){
    memmove(p->elems, (char *)p->elems + p->elem_size, (p->log_len - 1) * p->elem_size);
  }
  p->log_len--;
}

void PQueueDispose(PQueue * p){
  if(p->free_fn != NULL){
    for(int i = 0 ; i < p->log_len; i++){
      p->free_fn((char *)p->elems + i * p->elem_size);
    }
  }
  free(p->elems);
}
