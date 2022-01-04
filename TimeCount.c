#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern board;
extern Timeflag;

void *Countdown()
{
    int min = 2, sec = 0;
    time_t time_sec = 0;
    time_t old_sec = 0;
    printf("\n");
    time(&time_sec);
    old_sec = time_sec;
    while(min > 0 || sec > 0)
    {
        if(Timeflag == 1)
        {
            min = 2;
            sec = 0;
            Timeflag = 0;
        }
        time(&time_sec);
        if(time_sec != old_sec)
        {
            old_sec = time_sec;
            if(sec > 0)
                sec--;
            else
            {
                sec = 59;
                if(min > 0)
                    min--;
            }
            if(Timeflag != 2)
            printf("        CountDown--%02d:%02d\r      ", min, sec);
        }
    }
}

