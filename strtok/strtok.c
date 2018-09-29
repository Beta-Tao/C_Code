#include <string.h>
#include <stdio.h>

//Just want to test Git
int main(void)
{
    char str[] = "root:x::0:root:/root:/root:/bin/bash:";
    char *token;

    token = strtok(str, ":");
    printf("%s\n", token);
    while ((token = strtok(NULL, ":")) != NULL)
        printf("%s\n", token);
    return 0;
}