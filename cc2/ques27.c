#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#define MAX_THREAD


int n;

void *isPrime(void *vargp)
{

    if(n%2)
        printf("Odd Number\n");
    else
        printf("Even Number\n");
    
    int flag = 0;
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("Not Prime\n");
    else
        printf("Prime\n");
    
}
int main()
{
    printf("Enter the number :");
    scanf("%d",&n);
    pthread_t thread_id;
    printf("Thread Created\n");
    
    pthread_create(&thread_id, NULL, isPrime, NULL);
    (void)pthread_join(thread_id, NULL);
    printf("Thread Joined\n");
    exit(0);
    return 0;
}