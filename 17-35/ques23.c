// Write a program to a create child process and display the process ID of parent and child processes.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    pid_t childpid;
    childpid = fork();
    if (childpid == -1)
    {
        perror("Failed to fork");
        return 1;
    }
    if (childpid == 0)
        /* child code */
        printf("I am child %ld\n", (long)getpid());
    else
        /* parent code */
        printf("I am parent %ld\n", (long)getpid());
    return 0;
}
