#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, wrt;
int read_count = 0;
int data = 10;

void* reader(void* arg) {
    int id = *(int*)arg;

    sem_wait(&mutex);
    read_count++;
    if(read_count == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("Reader %d reads data = %d\n", id, data);

    sem_wait(&mutex);
    read_count--;
    if(read_count == 0)
        sem_post(&wrt);
    sem_post(&mutex);

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    sem_wait(&wrt);

    data = data + 5;
    printf("Writer %d writes data = %d\n", id, data);

    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int id1 = 1, id2 = 2, id3 = 1;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&w1, NULL, writer, &id3);
    pthread_create(&r2, NULL, reader, &id2);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
