#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ     27

main()
{
    int shmid;
    key_t key;
    char *shm, *s;


    key = 8000; // to get the segment created by server

    
     // Locate the segment. If not exists, exit.
    
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the segment to our data space. If unsuccesssful, exit.
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read the content of server
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');

   // Now change the first character of the segment to indicate we have read the segment.
    *shm = '#';
    
    exit(0);
}