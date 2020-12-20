#ifndef LINKED_ARRAY_LIST_H_
#define LINKED_ARRAY_LIST_H_

#include <stdlib.h>

typedef void (*FreeFunction)(void* elem);

typedef struct{
    //TODO
}LAL;

// Initialize linked list with passed array
void LALInit(LAL* lal, void* array, int elem_size, int array_length, FreeFunction freeFunction);

// Get element by index
void* LALGet(LAL* lal, size_t index);

// Get array by interval
void* LALGetInterval(LAL* lal, size_t start, size_t end);

// Append element
void LALAppend(LAL* lal, void* elem_address);

// Append elements
void LALAppendArray(LAL* lal, void* array, int array_length);

// Remove element by index
void LALRemove(LAL* lal, size_t index);

// Return quantity of elements
size_t LALSize(LAL* lal);

#endif