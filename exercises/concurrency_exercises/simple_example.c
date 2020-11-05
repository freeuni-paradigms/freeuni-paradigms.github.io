#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
void* func(void * arg) {
	int *counter = (int*) arg;
	printf("hello %d\n", *counter);
}

int main() {
	pthread_t *thread = malloc(sizeof(pthread_t));
	sem_t * sem = malloc(sizeof(sem_t));
	sem_init(sem, 0, 1);
	sem_wait(sem);
	printf("here\n");
	int a = 1;
	pthread_create(thread, NULL, func, &a);
	pthread_join(*thread, NULL);
	return 0;
}	
