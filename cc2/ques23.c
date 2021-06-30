
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    
    int pid = fork();

    if(pid)
    {
        printf("I am the child Process with %d pid\n", getpid());
    }
    else
    {
        printf("I am the Parent Process with %d pid\n", getpid());
    }

    return 0;
}