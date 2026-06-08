#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread_func(void *arg)
{
    char **thread_fill = (char**)arg;
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", thread_fill[i]);
    }
    printf("the thread has ended\n");
}

int main()
{
    pthread_t threads[4];
    char *thread_fill[4][5] = {
    {"message 11", "message 12", "message 13", "message 14", "message 15"},
    {"message 21", "message 22", "message 23", "message 24", "message 25"},
    {"message 31", "message 32", "message 33", "message 34", "message 35"},
    {"message 41", "message 42", "message 43", "message 44", "message 45"}
    };
    for (int i = 0; i < 4; i++)
    {
        if(pthread_create(&threads[i], NULL, thread_func, &thread_fill[i]))
        {
            printf("thread creation error\n");
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (pthread_join(threads[i], NULL) != 0) 
        {
            perror("thread waiting error\n");
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 1; i < 6; i++)
    {
        printf("parent thread: %d\n", i);
    }
    printf("the thread has ended\n");
}

