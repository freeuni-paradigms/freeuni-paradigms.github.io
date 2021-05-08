#include "solution.h"

#include <string.h>
#include <stdio.h>

void LALInit(LAL* lal, void* array, int elem_size, int array_length, FreeFunction freeFunction){
    lal->elem_size = elem_size;
    lal->freeFunction = freeFunction;
    lal->head = NULL;
    lal->tail = lal->head;
    lal->size = 0;

    if(array != NULL)
        LALAppendArray(lal, array, array_length);
}

struct Node* FindNodeByIndex(LAL* lal, size_t index){
    size_t curr_index = 0;
    struct Node* curr_node = lal->head;
    while(curr_index != index){
        curr_node = curr_node->next;
        curr_index++;
    }
    return curr_node;
}

void* LALGet(LAL* lal, size_t index){
    return FindNodeByIndex(lal, index)->elem;
}

void* LALGetInterval(LAL* lal, size_t start, size_t end){
    int length = end - start + 1;
    void* result_array = malloc(lal->elem_size * length);

    struct Node* curr_node = FindNodeByIndex(lal, start);
    size_t curr_index = start;

    for(int i = 0; i <length; i++){
        void* destination = (char*)result_array + i * lal->elem_size;
        void* source = curr_node->elem;
        memcpy(destination, source, lal->elem_size);
        curr_node = curr_node->next;
    }

    return result_array;
}

void LALAppend(LAL* lal, void* elem_address){
    if(lal->size == 0){
        lal->head = malloc(sizeof(struct Node));
        lal->head->previous = NULL;
        lal->head->next = NULL;
        lal->head->elem = malloc(lal->elem_size);
        memcpy(lal->head->elem, elem_address, lal->elem_size);
        lal->tail = lal->head;
    } else {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->previous = lal->tail;
        new_node->next = NULL;
        new_node->elem = malloc(lal->elem_size);
        memcpy(new_node->elem, elem_address, lal->elem_size);
        lal->tail->next = new_node;
        lal->tail = new_node;
    }
    lal->size++;
}

void LALAppendArray(LAL* lal, void* array, int array_length){
    for(int i = 0; i < array_length; i++){
        void* elem_address = (char*)array + i * lal->elem_size;
        LALAppend(lal, elem_address);
    }
}

void LALRemove(LAL* lal, size_t index){
    struct Node* node = FindNodeByIndex(lal, index);
    
    if(node->previous == NULL && node->next == NULL){
        lal->head = NULL;
        lal->tail = lal->head;
    } else if(node->next == NULL){
        lal->tail = node->previous;
        lal->tail->next = NULL;
    } else if(node->previous == NULL){
        lal->head = node->next;
        lal->head->previous = NULL;
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    if (lal->freeFunction != NULL)
        lal->freeFunction(node->elem);
    free(node->elem);
    free(node);
    lal->size--;
}

size_t LALSize(LAL* lal){
    return lal->size;
}
