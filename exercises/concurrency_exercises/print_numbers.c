#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define MAX_NUM 100

void RandomSleep() {
	int k = rand();
	if (k % 3 == 0) {
		usleep(100);
	}
}

typedef struct {
	int counter;
	sem_t * evenLock;
	sem_t * oddLock;
} dataT;

void * EvenPrinter(void * data) {
	dataT * d = (dataT *)data;
	for (int i=2; i<=100; i+=2) {
		RandomSleep();
		sem_wait(d->evenLock);
		printf("%d\n", i);
		sem_post(d->oddLock);
	}
	return NULL;
}

void * OddPrinter(void * data) {
	dataT * d = (dataT *)data;
	for (int i=1; i<=100; i+=2) {
		RandomSleep();
		sem_wait(d->oddLock);
		printf("%d\n", i);
		sem_post(d->evenLock);
	}
	return NULL;
}
int main() {
	pthread_t * tEven = malloc(sizeof(pthread_t));
	pthread_t * tOdd = malloc(sizeof(pthread_t));
	dataT * data = malloc(sizeof(dataT));
	data->evenLock = malloc(sizeof(sem_t));
	data->oddLock = malloc(sizeof(sem_t));
	sem_init(data->evenLock, 0, 0);
	sem_init(data->oddLock, 0, 1);

	pthread_create(tEven, NULL, EvenPrinter, data);
	pthread_create(tOdd, NULL, OddPrinter, data);

 	pthread_join(*tEven, NULL);
    	pthread_join(*tOdd, NULL);

	free(tEven);
	free(tOdd);
	free(data->evenLock);
	free(data->oddLock);
	free(data);

	pthread_exit(NULL);
}
