#include <stdio.h>
#include <pthread.h>

int shared = 0;  // shared variable

pthread_mutex_t lock; // mutex lock

// Function for thread
void* increment(void* arg) {
    for(int i = 0; i < 5; i++) {

        pthread_mutex_lock(&lock);   // LOCK

        shared++;  // critical section
        printf("Thread %d: shared = %d\n", *(int*)arg, shared);

        pthread_mutex_unlock(&lock); // UNLOCK
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, &id1);
    pthread_create(&t2, NULL, increment, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final value of shared = %d\n", shared);

    return 0;
}
