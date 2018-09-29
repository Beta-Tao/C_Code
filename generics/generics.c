#include "generics.h"

void *max(void *data[], int num, cmp_t cmp)
{
    int i;
    void *temp = data[0];
    for (i = 1; i < num; i++)
    {
        if (cmp(temp, data[i]) < 0)
            temp = data[i];     //指针的赋值
    }
    return temp;
}
