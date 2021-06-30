// 20. Write a C program which renames all .txt files as .text files.
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    int i;
    char temp[50], cmd[20];
    system("dir");
    system("dir > listforques20");
    fp = fopen("listforques20", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", temp);
        i = 0;
        strcpy(cmd, "mv ");
        while (temp[i] != '.')
        {
            i++;
        }
        if (temp[i + 1] == 't' && temp[i + 2] == 'x' && temp[i + 3] == 't')
        {
            strcat(cmd, temp);
            strcat(cmd, " ");
            temp[i + 2] = 'e';
            temp[i + 3] = 'x';
            temp[i + 4] = 't';
            temp[i + 5] = '\0';
            strcat(cmd, temp);
            //printf("%s\n",cmd);
            system(cmd);
        }
        //printf(" %s \n",temp);
    }
    printf("after changing: ");
    system("dir");
    return 0;
}