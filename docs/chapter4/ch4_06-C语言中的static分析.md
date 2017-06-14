## 修饰局部变量

说明：static修饰全局变量(静态全局变量)的时候，只对定义它的源文件可见，其它的源文件访问该
变量时会出错。

验证：
创建以下几个文件：file1.c file1.h file2.

file1.h
```c
#include <stdio.h>

void printstr();
```

file1.c
```c
#include "file1.h"

static char *str = "hello world.";  //定义全局静态变量char *str;

void printstr()
{
    printf("%s\n", str);
}
```

file2.c
```c
#include <stdio.h>

int main(void)
{
    printf("%s\n", str);  //引用全局静态变量str.(错误)
    printstr();
}
```

这种使用方法在编译时报错。

![20170614_ch4_6_1](\images\chapter4\20170614_ch4_6_1.png)
