// 22. Write Programs to
// a) Report the behavior of the OS to get the CPU type and model, kernel version.

#include<stdio.h>
#include<stdlib.h>
int main()
{
 system("cat /proc/cpuinfo | grep model\\ name");
 system("cat /proc/version");
 return 0;
}
