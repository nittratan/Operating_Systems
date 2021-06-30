// 21. Implement a C program that reports the number of file names in the current working directory that consist of exactly five characters.

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int i;
    char temp[50], cmd[20];
    system("dir > listforques21");
    fp = fopen("listforques21", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", temp);
        if (strlen(temp) == 5)
        {
            printf(" %s \n", temp);
        }
    }
    return 0;
}