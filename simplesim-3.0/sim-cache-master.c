#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int tick = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread_entry(void *waitNum)
{

    while (tick < 100)
    {
        pthread_mutex_lock(&mutex);
        while ((tick % 2) == *((int *)waitNum))
            pthread_cond_wait(&cond, &mutex);
        ++tick;
        printf("from thread: %d, tick = %d\n", *((int *)waitNum), tick);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int num1 = 0, num2 = 1;
    pthread_create(&thread1, NULL, thread_entry, (void *)(&num1));
    pthread_create(&thread2, NULL, thread_entry, (void *)(&num2));
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}