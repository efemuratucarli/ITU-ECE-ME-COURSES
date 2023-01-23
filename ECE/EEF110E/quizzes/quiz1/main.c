#include <stdio.h>
#include <stdlib.h>

char* date2str(int day,int month,int year);

int main()
{
    int day;
    int month;
    int year;
    char* res;

    day=31;month=13;year=2022;
    res=date2str(day,month,year);
    printf("%s",res);

    return 0;
}