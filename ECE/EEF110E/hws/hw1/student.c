//***************************************
//** SUBMIT ONLY THIS FILE
//** DO NOT CHANGE ANYTHING
//** ONLY ADD THE IMPLEMENTATION
//***************************************
#include <stdio.h>
#include <math.h>

//****************** Q1 ******************
void generate(int n)
{
    //implementation goes here
    int c = n;
    int r = n ;
    int flag = 1 ;
    for(int i=1; i<=(2*c - 1); i++)
    {
        r = c ;
        for(int j=1; j<=((2*c - 1)-(2*n - 1))/2; j++)
        {
            printf("%3d", r);
            r = r - 1 ;
        }
        for(int y=1; y<=(2*r - 1); y++)
        {
            printf("%3d", r);
        }
        for(int z=1; z<=((2*c - 1)-(2*n - 1))/2; z++)
        {
            r = r + 1;
            printf("%3d", r);
        }
        if (n != 1 && flag)
        {
            n = n - 1 ;
        }
        else
        {
            flag = 0 ;
            n = n + 1 ;
        }
        printf("\n");
    }
}

//****************** Q2 ******************
double pol(double); //do not implement here
double dpol(double);//do not implement here
double iterate(double a)
{
    if (fabs(pol(a)-0)>= 0.001)
    {
        a = a - (pol(a)/dpol(a));
        return iterate(a);
    }
    else
    {
        return a;
    }
}