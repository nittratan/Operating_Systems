#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    
    key = 8000;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //Put some things for the client to read.
    s = shm;

    char content[] = "Process is Now Running";
    for (int i=0; i<sizeof(content); i++)
        *s++ = content[i];
    *s = NULL;

    printf("Shared Memory Content: %s\n",shm);
    // Wait until client changes the first character of the segment, indicating that client has read the content of segment.
    while (*shm != '#')
        sleep(1);

    printf("Shared Memory Content: %s\n",shm);
    exit(0);

    return 0;
}