## 静态全局变量

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

这种使用方法在编译时报错
![20170614_ch4_6_1](/images/chapter4/20170614_ch4_6_1.png)

去掉file2.c中的错误语句，编译通过。
![20170614_ch4_06_2](/images/chapter4/20170614_ch4_06_2.png)

总结：用static修饰全局变量叫静态全局变量，只能被定义它的源文件调用，其它的源文件不能调用
该静态全局变量。也就是说，用static修饰全局变量的时候，相当于把该全局变量对其它的源文件隐藏。

## 静态局部变量

用static修饰的局部变量叫静态局部变量，静态局部变量其作用域内的变量或函数访问。虽然存在于整个程序的生命周期中，但是不能被其它的函数的源文件访问。如果静态局部变量如果没有被用户初始化，则会被编译器自动赋值为0，并且以后每次调用的时候都使用上次调用后的值。

示例程序：
file1.h
```c
#include <stdio.h>

void printstr();
```

file1.c
```c
#include "file1.h"

void printstr()
{
    char i = 0;   //普通局部变量
    static char j = 0;  //静态局部变量
    printf("i = %d, j = %d.\n", i, j);
    i++;
    j++;
}
```

file2.c
```c
#include <stdio.h>
#include "file1.h"

int main(void)
{
    printstr();
    printstr();
    printstr();
    printstr();
    printstr();
    printf("%d, %d.\n", i, j);  //(错误)去掉直接调用静态局部变量的语句。

    return 0;
}
```

编译不通过
![20170614_ch4_06_3](/images/chapter4/20170614_ch4_06_3.png)

去掉其中错误的语句以后，编译通过
![20170614_ch4_06_4](/images/chapter4/20170614_ch4_06_4.png)

总结：静态局部变量只对其作用域内的变量或函数，并且，静态局部变量每次使用后，再次调用的时候使用上次的值。

## (static函数)静态函数

静态函数，作用于本源文件，作用是对用户隐藏一些函数的具体实现。

file1.h
```c
#include <stdio.h>

static int called();  //用static修饰函数，限定函数的作用域。
void printstr();
```
file1.c
```c
#include "file1.h"

static int called()   //函数定义
{
    return 10;
}
void printstr()
{
    int retval;
    retval = called();
    printf("retval = %d\n", retval);
}
```
file2.c
```c
#include <stdio.h>
#include "file1.h"

int main()
{
    printstr();

    int val;
    val = called();   //(错误)由于called()函数已经用static修饰，所以对file2.c文件不可见，
    printf("val = %d\n", val);

    return 0;
}
```

编译不通过
![20170614_ch4_06_5](/images/chapter4/20170614_ch4_06_5.png)

去掉file2.c中的错误代码片段之后，编译通过
![20170614_ch4_06_6](/images/chapter4/20170614_ch4_06_6.png)

总结：static修饰函数的时候，把函数的作用域限定在了本源文件中，因为static函数对其它源文件是不可见的，也就实现了对用户隐藏函数的细节。
可以看出，隐藏是static的一大特性。不管是全局变量，局部变量，还是函数，经过static修饰以后，限定了该全局变量，局部变量或者是函数的可见范围，对其它的一些有不可见性
