#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;   // counts empty spaces
sem_t full;    // counts filled spaces
sem_t mutex;   // controls buffer access

void* producer(void* arg) {
    int item;

    for(int i = 1; i <= 5; i++) {
        item = i;

        sem_wait(&empty);   // wait if buffer is full
        sem_wait(&mutex);   // enter critical section

        buffer[in] = item;
        printf("Producer produced item %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // exit critical section
        sem_post(&full);    // increase filled count

        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg) {
    int item;

    for(int i = 1; i <= 5; i++) {
        sem_wait(&full);    // wait if buffer is empty
        sem_wait(&mutex);   // enter critical section

        item = buffer[out];
        printf("Consumer consumed item %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // exit critical section
        sem_post(&empty);   // increase empty count

        sleep(2);
    }

    return NULL;
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
