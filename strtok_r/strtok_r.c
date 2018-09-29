#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *str1, *str2, *token, *subtoken;
    char *saveptr1, *saveptr2;
    int k;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s string delim subdelim.\n", argv[0]);
        return 0;
    }

    for (k = 1, str1 = argv[1]; ; k++, str1 = NULL)
    {
        token = strtok_r(str1, argv[2], &saveptr1);     //记录第一大类分割串
        if (token == NULL)
            break;
        printf("%d: %s\n", k, token);
        
        for (str2 = token; ; str2 = NULL)       //记录第二大类分割串，当subtoken为空时表示结束
        {
            subtoken = strtok_r(str2, argv[3], &saveptr2);
            if (subtoken == NULL)
                break;
            printf("--->%s\n", subtoken);
        }
    }
    
    return 0;
}