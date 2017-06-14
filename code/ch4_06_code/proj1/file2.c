#include <stdio.h>
#include "file1.h"

int main(void)
{
    printstr();
//  printf("%s\n", str);  //这行代码会报错，因为str只对file1可见，file2不能访问。

    return 0;
}
