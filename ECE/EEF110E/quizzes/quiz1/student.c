#include <stdlib.h> 

char* date2str(int day,int month,int year)
{
    char *date;
    if (day < 1 || day > 31 || month < 1 || month > 12) 
    {
        date = "invalid\0";
        return date;
    }
    date = malloc(sizeof(char) * 11);
    char digits[] = "0123456789";
    *date = digits[day/10];
    *(date+1) = digits[day % 10];
    *(date+2) = '.';
    *(date+3) = digits[month / 10];
    *(date+4) = digits[month % 10];
    *(date+5) = '.';
    *(date+6) = digits[year / 1000];
    *(date+7) = digits[(year / 100) % 10];
    *(date+8) = digits[(year / 10) % 10];
    *(date+9) = digits[year % 10];
    *(date+10) = '\0';
    return date;
}