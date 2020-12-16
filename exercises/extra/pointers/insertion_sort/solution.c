#include "insertion_sort.h"

void InsertionSort(void * elems, int length, int elem_size, int(*cmp)(void * , void *)){
    for (int i = 1; i < length; i++) {
      char temp[elem_size];
      memcpy(temp, (char *)elems + i * elem_size, elem_size);
      int j = i - 1;
      while (j >= 0 && (cmp((char *)elems + j * elem_size, temp) > 0)) {
	void * prev = (char *)elems + (j+1) * elem_size;
	void * curr = (char *)elems + j * elem_size;
	memcpy(prev, curr, elem_size);
	j = j - 1; 
      }
      void * prev = (char *)elems + (j+1) * elem_size;
      memcpy(prev, temp, elem_size);
    }
}
