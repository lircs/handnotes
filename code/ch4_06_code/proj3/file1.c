#include "file1.h"

static int called()
{
    return 10;
}
void printstr()
{
    int retval;
    retval = called();
    printf("retval = %d\n", retval);
}
