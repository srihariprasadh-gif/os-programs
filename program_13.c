#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
pthread_mutex_t chopstick[N];
void* philosopher(void* arg) {
    int id = *(int*)arg;

    int left = id;
    int right = (id + 1) % N;

    printf("Philosopher %d is thinking\n", id);

    pthread_mutex_lock(&chopstick[left]);
    printf("Philosopher %d picked left chopstick\n", id);

    pthread_mutex_lock(&chopstick[right]);
    printf("Philosopher %d picked right chopstick\n", id);

    printf("Philosopher %d is eating\n", id);
    sleep(1);

    pthread_mutex_unlock(&chopstick[right]);
    printf("Philosopher %d released right chopstick\n", id);
    pthread_mutex_unlock(&chopstick[left]);
    printf("Philosopher %d released left chopstick\n", id);
    return NULL;
}
int main() {
    pthread_t ph[N];
    int id[N];

    for(int i = 0; i < N; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
        id[i] = i;
    }

    for(int i = 0; i < N; i++) {
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++) {
        pthread_join(ph[i], NULL);
    }
    for(int i = 0; i < N; i++) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}
