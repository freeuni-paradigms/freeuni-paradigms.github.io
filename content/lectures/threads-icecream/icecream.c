/* Ice Cream Shop */

/* Manager   1 */
/*    | */
/* Clerk     40 */
/*    | */
/* Client    10 [1 .. 4] */
/*    | */
/* Cashier   1 */

#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CLIENTS 10

typedef struct {
  sem_t lock;      // 1
  sem_t requested; // 0
  sem_t inspected; // 0
  bool passed;
} Inspection;

typedef struct {
  sem_t lock; // 1
  int number; // 0
} Line;

typedef struct {
  sem_t requested;            // 0
  sem_t clients[NUM_CLIENTS]; // 0
} CheckOut;

Inspection inspection;
Line line;
CheckOut checkout;

void SemaphoreInit() {
  sem_init(&inspection.lock, 0, 1);
  sem_init(&inspection.requested, 0, 0);
  sem_init(&inspection.inspected, 0, 0);
  sem_init(&line.lock, 0, 1);
  sem_init(&checkout.requested, 0, 0);
  for (int i = 0; i < NUM_CLIENTS; ++i) {
    sem_init(&checkout.clients[i], 0, 0);
  }
}

typedef struct {
  int id;
  int num_cones;
} ClientArgs;

typedef struct {
  char id[15];
  sem_t *done;
} ClerkArgs;

int RandomInt(int from, int to) {
  assert(from <= to);
  return rand() % (to - from + 1) + from;
}

bool Inspect() {
  sleep(RandomInt(1, 2));
  printf("Manager: inspected icecream\n");
  return RandomInt(0, 1);
}

void *Manager(void *args_ptr) {
  int total_cones = *(int *)args_ptr;
  int num_inspected = 0;
  int num_approved = 0;
  while (num_approved < total_cones) {
    sem_wait(&inspection.requested);
    inspection.passed = Inspect();
    sem_post(&inspection.inspected);
    num_inspected++;
    if (inspection.passed) {
      num_approved++;
    }
  }
  printf("Manager done: inspected %d approved %d\n", num_inspected,
         num_approved);
  return NULL;
}

void MakeNewIceCream(char *id) {
  sleep(RandomInt(1, 2));
  printf("Clerk %s: made new icecream\n", id);
}

void *Clerk(void *args_ptr) {
  ClerkArgs *args = (ClerkArgs *)args_ptr;
  bool passed = false;
  while (!passed) {
    MakeNewIceCream(args->id);
    sem_wait(&inspection.lock);
    sem_post(&inspection.requested);
    sem_wait(&inspection.inspected);
    passed = inspection.passed;
    printf("Clerk %s: made icecream %d\n", args->id, passed);
    sem_post(&inspection.lock);
  }
  sem_post(args->done);
  printf("Clerk %s: done\n", args->id);
  free(args);
  return NULL;
}

// Takes ownership of memory at given pointer.
void *Client(void *args_ptr) {
  ClientArgs *args = (ClientArgs *)args_ptr;
  sem_t done;
  sem_init(&done, 0, 0);
  for (int i = 0; i < args->num_cones; ++i) {
    pthread_t tid;
    ClerkArgs *clerk = malloc(sizeof(ClerkArgs));
    assert(clerk != NULL);
    sprintf(clerk->id, "%d-%d", args->id, i);
    clerk->done = &done;
    pthread_create(&tid, NULL, Clerk, clerk);
  }
  for (int i = 0; i < args->num_cones; ++i) {
    sem_wait(&done);
    printf("Client %d: received icecream\n", args->id);
  }
  printf("Client %d: all %d icecreams received\n", args->id, args->num_cones);
  sem_wait(&line.lock);
  int number = line.number;
  line.number++;
  sem_post(&line.lock);
  printf("Client %d: got line number %d\n", args->id, number);
  sem_post(&checkout.requested);
  sem_wait(&checkout.clients[number]);
  free(args_ptr);
  printf("Client %d: done\n", args->id);
  return NULL;
}

void BillClient(int client_id) {
  printf("Cashier: billing client %d\n", client_id);
}

void *Cashier(void *_) {
  for (int i = 0; i < NUM_CLIENTS; ++i) {
    sem_wait(&checkout.requested);
    BillClient(i);
    sem_post(&checkout.clients[i]);
  }
  printf("Cashier: done\n");
  return NULL;
}

int main() {
  SemaphoreInit();
  int total_cones = 0;
  pthread_t cl_tids[NUM_CLIENTS];
  pthread_t m_tid;
  pthread_t c_tid;
  for (int i = 0; i < NUM_CLIENTS; ++i) {
    int num_cones = RandomInt(1, 4);
    total_cones += num_cones;
    ClientArgs *args = malloc(sizeof(ClientArgs));
    assert(args != NULL);
    args->id = i;
    args->num_cones = num_cones;
    pthread_create(&cl_tids[i], NULL, Client, args);
  }
  pthread_create(&m_tid, NULL, Manager, &total_cones);
  pthread_create(&c_tid, NULL, Cashier, NULL);
  for (int i = 0; i < NUM_CLIENTS; ++i) {
    pthread_join(cl_tids[i], NULL);
  }
  pthread_join(m_tid, NULL);
  pthread_join(c_tid, NULL);
  return 0;
}
