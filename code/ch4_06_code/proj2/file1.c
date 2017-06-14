#include "file1.h"

void printstr()
{
    char i = 0;   //普通局部变量
    static char j = 0;  //静态局部变量
    printf("i = %d, j = %d.\n", i, j);
    i++;
    j++;
}
