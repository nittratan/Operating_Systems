// Create a file with few lines, Write a C program to read the file and delete the spaces more than one in the file (use UNIX file API’s).

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buf1[50], buf2[50];
    int i = 0, j = 0, n;
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY, 0754);
    read(fd1, buf1, sizeof(buf1));
    for (i = 0; i < strlen(buf1); i++)
    {
        if (((buf1[i] == ' ') && (buf1[i + 1] != ' ')) || (((buf1[i] != ' '))))
        {
            buf2[j++] = buf1[i];
        }
        else
        {
            buf2[j++] = buf1[i];
            for (n = i + 1; n < strlen(buf1); n++)
            {
                buf1[n] = buf1[n + 1];
            }
        }
    }
    write(fd2, buf2, sizeof(buf2));
    close(fd1);
    close(fd2);
    return 0;
}
