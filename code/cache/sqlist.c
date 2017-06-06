#include <stdio.h>

const MAXSIZE = 20;

enum returninfo {success, fail, overflow, underflow, range_error};

int dataarray[MAXSIZE];
int count;    //节点个数及线性表长度

int *p = &dataarray

returninfo create(int num);
bool empty(void);
int length(void);
returninfo traverse(void);
returninfo get(int pos, int &item);
returninfo replace(int pos, const int &item);
returninfo insert(int pos, const int &item);
returninfo remove(void);
returninfo invertlist(void);


returninfo create(int num)
{
    count = num;
    printf("请依次输入数据(用空格隔开)：\n", );
    for(int i = 0; i < count; i++)
        scanf("%d", &dataarray[i]);
    return success;
}

bool empty(void)
{
    if(count == 0)
      return true;
    else
      return false;
}

returninfo traverse(void)
{
    if(empty())
        return underflow;
    printf("遍历的数据依次为：\n");
    for(int i = 0; i < count; i++)
        printf("%d\n", dataarray[i]);
    return success;
}

returninfo traverse(void)
{
    if(empty())
      return underflow;
    printf("遍历的数据依次为：\n" );
    for(int i = 0; i < count; i++)
        printf("%d\n", *p(i));
    return success;
}
