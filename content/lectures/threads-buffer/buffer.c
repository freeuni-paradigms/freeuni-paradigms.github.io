// Two way locking/communication

char buffer[8];
sem_t full;  // 0
sem_t empty; // 8

void *Writer(void *args) {
  for (int i = 0; i < 40; ++i) {
    sem_wait(&empty);
    buffer[i % 8] = i;
    sem_post(&full);
  }
}

void *Reader(void *args) {
  for (int i = 0; i < 40; i++) {
    sem_wait(&full);
    Process(buffer[i % 8]);
    sem_post(&empty);
  }
}

int main() {
  pthread_t w, r;
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, 8);
  pthread_create(&w, NULL, Writer, NULL);
  pthread_create(&r, NULL, Reader, NULL);
  pthread_join(w);
  pthread_join(r);
  sem_destroy(&full);
  sem_destroy(&empty);
  return 0;
}
