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

// ორი სემაფორა
typedef struct {
	int counter;
	sem_t * evenLock;
	sem_t * oddLock;
} dataT;

void * EvenPrinter(void * data) {
	dataT * d = (dataT *)data;

	return NULL;
}

void * OddPrinter(void * data) {
	dataT * d = (dataT *)data;

	return NULL;
}
int main() {
	// ნაკადებისთვის მეხსიერების ალოკაცია
	
	// არგუმენტისთვის მეხსიერების ალოკაცია
	// სტრუქტურის წევრების (სემაფორების ჩათვლით) ინიციალიზაცია
	sem_init(sem*, 0, starting_value);
	
	// ნაკადების გაშვება
	pthread_create(thread_name, NULL, func_name, func_data);

	// ნაკადებისთვის დალოდება
	pthread_join(*thread_name, NULL);

	// მეხსიერების გათავისუფლება (მალოკი რასაც დაუწერეთ)
	pthread_exit(NULL);
}
