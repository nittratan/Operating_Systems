#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

FILE *temp_file;
void leave(int sig);

int main()
{
    (void)signal(SIGINT, leave);
    temp_file = fopen("tmp", "w");
    for (;;)
    {
        /*
                 * Do things....
                 */
        printf("Ready...\n");
        (void)getchar();
    }
    /* can't get here ... */
    exit(EXIT_SUCCESS);
    return 0;
}

// SIGHUP	1	Hang up detected on controlling terminal or death of controlling process
// SIGINT	2	Issued if the user sends an interrupt signal (Ctrl + C)
// SIGQUIT	3	Issued if the user sends a quit signal (Ctrl + D)
// SIGFPE	8	Issued if an illegal mathematical operation is attempted
// SIGKILL	9	If a process gets this signal it must quit immediately and will not perform any clean-up operations
// SIGALRM	14	Alarm clock signal (used for timers)
// SIGTERM	15	Software termination signal (sent by kill by default)
// kill -l
void leave(int sig)
{
    printf("\nSIGINT Recieved, Exiting");
    fprintf(temp_file, "\nInterrupted..\n");
    fclose(temp_file);
    exit(sig);
}