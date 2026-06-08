#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_func(void *arg)
{
    int n = *(int*)arg;
    sleep(n);
    printf("%d\n", n);
}

int main()
{
    printf("Write a count elements in array:\n");
    int d = 0;
    scanf("%d", &d);
    if (d > 50)
    {
        printf("too many elements in the array\n");
        exit(1);
    }
    else
    {
        int arr[d];
        for(int i = 0; i < d; i++)
        {
            scanf("%d", &arr[i]);
        }
        pthread_t threads[d];
        for(int i = 0; i < d; i++)
        {
            pthread_create(&threads[i], NULL, thread_func, &arr[i]);
        }
        for(int i = 0; i < d; i++)
        {
            pthread_join(threads[i], NULL);
        }
    }
}