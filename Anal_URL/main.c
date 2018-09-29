#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *search;
    char *token, *subtoken;
    char *saveptr1, *saveptr2;
    int k;

    if (argc != 2)  //参数需要有两个，一个是文件名，另一个是动态网址名
    {
        printf("The argument is wrong!\n");
        return 0;
    }
    if ((search = strchr(argv[1], '?')) == NULL)   //查找是否有问号
        return 0;
    else
    {
        token = search + 1; //略过问号
        for (k = 1; ; k++, token = NULL)
        {
            token = strtok_r(token, "&", &saveptr1);
            if (token == NULL)
                return 0;
            printf("Search Part-%2d: ", k);

            subtoken = strtok_r(token, "=", &saveptr2);
            if (*saveptr2 == '\0')
                printf("Key = %s\tValue = NULL\n", subtoken);
            else
            {
                printf("Key = %s\tValue = %s\n", subtoken, saveptr2);
            }
        }
    }
    return 0;
}