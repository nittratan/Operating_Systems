// 22. Write Programs to
// b) Get the amount of memory configured into the computer, amount of memory currently available.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("cat /proc/meminfo | grep Mem");
    return 0;
}