#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <assert.h>

typedef struct{
  void * elems;
  int * priorities;
  int * bytes;
  int bytes_size;
  int log_len;
  void (*free_fn)(void *);
}PQueue;

//Initialize priority queue.
void PQueueNew(PQueue * p, void (*free_fn)(void *));

//Push element at the correct position.
void PQueuePush(PQueue * p, void * elem, int elem_size, int priority);

//Pop first element from the priority queue.
void * PQueuePop(PQueue * p);

//Free all allocated memory.
void PQueueDispose(PQueue * p);
