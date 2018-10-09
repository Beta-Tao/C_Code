#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    FILE *fp = fopen("timelog.txt", "a+");
    struct tm *pNewTime;
    time_t newTime;

    //对文件指针进行判断
    if (fp == NULL)
    {
        perror("Open timelog.txt: ");
        exit(1);
    }

    //死循环打印log
    while (1)
    {
        //printf("Hello\n");
        newTime = time(NULL);
        //printf("newTime: %ld\n", newTime);
        pNewTime = localtime(&newTime);
        //printf("year: %d\n", pNewTime->tm_year);
        fprintf(fp, "%d-%d-%d %d:%d:%d\n", 
                pNewTime->tm_year + 1900, pNewTime->tm_mon + 1, pNewTime->tm_mday, 
                pNewTime->tm_hour, pNewTime->tm_min, pNewTime->tm_sec);
        fflush(fp);
        sleep(1);
    }
    return 0;
}