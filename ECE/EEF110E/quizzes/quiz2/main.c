#include <stdio.h>
#include <stdlib.h>

char* generateCircle(int,int,int);

int main()
{
    char* res=NULL;
    // res=generateCircle(0,0,50);
    res=generateCircle(2,2,4);
    printf("%s",res);

    if(res!=NULL)free(res);
}