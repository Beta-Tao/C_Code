#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    FILE *fp = fopen("timelog.txt", "a");
    struct tm *pNewTime = NULL;
    time_t newTime;
    if (fp == NULL)
    {
        perror("Open timelog.txt: ");
        exit(1);
    }

    while (1)
    {
        //printf("Hello\n");
        newTime = time(NULL);
        //printf("newTime: %ld\n", newTime);
        pNewTime = localtime(&newTime);
        //printf("year: %d\n", pNewTime->tm_year);
        fprintf(fp, "%d-%d-%d %d:%d:%d\n", 
                pNewTime->tm_year, pNewTime->tm_mon, pNewTime->tm_mday, 
                pNewTime->tm_hour, pNewTime->tm_min, pNewTime->tm_sec);
        sleep(1);
    }
    return 0;
}