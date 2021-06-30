// 24. Write a program to demonstrate the implementation of Inter Process Communication (IPC) "who | grep YourLoginName" using pipes.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pid;
    int fd[2];
    pipe(fd);
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(-1);
    }
    if (pid)
    {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execl("/usr/bin/wc", "wc", "-l", (char *)0);
        close(fd[0]);
    }
    else
    {
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execl("/usr/bin/who", "who", (char *)0);
        close(fd[1]);
    }
    return 0;
}
