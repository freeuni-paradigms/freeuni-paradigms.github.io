#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <assert.h>

typedef struct{

}PQueue;

//Initialize priority queue.
void PQueueNew(PQueue * p, int elem_size, void (*free_fn)(void *), int (*cmp)(void * , void *));

//Push element at the correct position.
void PQueuePush(PQueue * p, void * elem);

//Pop first element from the priority queue.
void PQueuePop(PQueue * p, void * elem);

//Free all allocated memory.
void PQueueDispose(PQueue * p);

