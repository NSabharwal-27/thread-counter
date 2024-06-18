#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_COUNT 18

int GLOBAL_COUNTER = 0;
pthread_mutex_t lock;

void *incrementCount(void *vargp) {
    int myid = *((int *)vargp);
    free(vargp);

    if (pthread_mutex_lock(&lock) == 0) {
        GLOBAL_COUNTER++;
        printf("tid:%d has incremented GLOBAL_COUNTER to: %d\n", myid, GLOBAL_COUNTER);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t tid[THREAD_COUNT];

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("mutex initialization has failed.\n");
        return 1;
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        if (pthread_create(&tid[i], NULL, incrementCount, (void *)id) != 0) {
            printf("Failed to create thread %d\n", i);
            free(id); // Clean up if thread creation fails
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
