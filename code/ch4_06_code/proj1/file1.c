#include "file1.h"

static char *str = "hello world.";  //定义静态全局变量char *str;只有在定义的源文件中可见，其它的源文件不可见

void printstr()
{
    printf("%s\n", str);
}
