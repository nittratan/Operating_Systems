// 17.Write a C program to kill a process by specifying its name rather than its PID.
#include <stdio.h>
#include <string.h>
int main()
{
    char cmd[50], cmd1[50], cmd2[50], log[50], pname[50], pid[50];
    FILE *fp;
    system("rm newpro");
    system("rm data");
    printf("enter ur login name\n");
    fgets(log, sizeof(log), stdin);
    strcpy(cmd, "ps -aux | grep ");
    strcat(cmd, log);
    system(cmd);
    printf("enter the name of the process u want to terminate\n");
    scanf("%s", pname);
    strcpy(cmd1, "ps -a | grep ");
    strcat(cmd1, pname);
    strcat(cmd1, " > newpro");
    system(cmd1);
    system("cut -f2 -d' ' newpro > data");
    fp = fopen("data", "r");
    fscanf(fp, "%s", pid);
    strcpy(cmd2, "kill ");
    strcat(cmd2, pid);
    system(cmd2);
    system(cmd);
    printf("the process %s is killed successfully", pname);
    return 0;
}
