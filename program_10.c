#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    pthread_t currentThread;

    currentThread = pthread_self();

    printf("Thread is running...\n");
    printf("Thread ID: %lu\n", currentThread);

    pthread_exit(NULL);   // exit from thread
}

int main() {
    pthread_t t1, t2;

    // (i) Create threads
    pthread_create(&t1, NULL, threadFunction, NULL);
    pthread_create(&t2, NULL, threadFunction, NULL);

    // (iii) Check whether two threads are equal
    if(pthread_equal(t1, t2)) {
        printf("Both threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }

    // (ii) Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads completed\n");

    pthread_exit(NULL);   // exit from main thread
}




