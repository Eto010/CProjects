#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread_func(void *arg)
{
    for(int i = 1; i < 6; i++)
    {
        printf("child thread: %d\n", i);
    }
    printf("the thread has ended\n");
}

int main()
{
    pthread_t thread;
    if(pthread_create(&thread, NULL, thread_func, NULL))
    {
        printf("thread creation error\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread, NULL) != 0) {
            perror("thread waiting error\n");
            exit(EXIT_FAILURE);
        }
    for(int i = 1; i < 6; i++)
    {
        printf("parent thread: %d\n", i);
    }
    printf("the thread has ended\n");
}
