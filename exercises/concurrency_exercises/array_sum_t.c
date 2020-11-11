#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 100
#define NUM_THREADS 10
#define MAX_NUM 10000

void generateArray(int *arr) {
    int sum = 0;
    for (int i = 0; i < ARRAY_LEN; i++) {
        arr[i] = rand() % MAX_NUM;
        sum += arr[i];
    }
    printf("Sum of array is %d\n", sum);
}

typedef struct {
    int *arr;
    int threadInd;
} dataT;

void *calculateSum(void *datat) {
    dataT *data = datat;
    int *sum = malloc(sizeof(int));
    *sum = 0;
    int sliceLen = (ARRAY_LEN - 1) / NUM_THREADS + 1;
    for (int i = 0; i < sliceLen; i++) {
        int ind = data->threadInd * sliceLen + i;
        if (ind >= ARRAY_LEN)
            break;
        *sum += data->arr[ind];
    }

    free(data);

    pthread_exit(sum);
}

int main() {
    srand(time(NULL));

    int *arr = malloc(sizeof(int) * ARRAY_LEN);
    generateArray(arr);

    int sum = 0;

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        dataT *data = malloc(sizeof(dataT));
        data->arr = arr;
        data->threadInd = i;
        pthread_create(&threads[i], NULL, calculateSum, data);
    }

    int *s;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &s);
        sum += *s;
        free(s);
    }

    printf("Calculated sum is: %d\n", sum);
    free(arr);
}