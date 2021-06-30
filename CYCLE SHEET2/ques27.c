// 27. Write a program to create a thread and let the thread check whether the given number is prime or not.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_prime(void *num)
{
    int *n = (int *)num;
    int i, flag = 0;
    for (int i = 2; i <= *n / 2; i++)
    {
        if (*n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (*n == 1)
    {
        printf("Not a prime number\n");
    }
    else
    {
        if (flag == 0)
        {
            printf("Prime number\n");
        }
        else
        {
            printf("Not a prime number\n");
        }
    }
}
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    pthread_t thread1;
    printf("Using thread to check whether a number is prime or not\n");
    if (pthread_create(&thread1, NULL, thread_prime, (void *)&n) < 0)
    {
        perror("pthread_creation");
        exit(1);
    }
    pthread_join(thread1, NULL);
    printf("Done\n");
    return 0;
}