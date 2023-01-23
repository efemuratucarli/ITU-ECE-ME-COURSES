#include <stdlib.h>
#include <math.h>

#define WIDTH 10

char* generateCircle(int x,int y,int rad)
{
    char* screen=NULL;
    screen = malloc(WIDTH*(WIDTH+1) + 1);
    int z = 0;
    while(z < WIDTH)
    {
        for(int i = 0; i < WIDTH; i++)
        {
            if((sqrt((i-x)*(i-x) + (z-y)*(z-y))<= rad))
            {
               screen[i+z*(WIDTH+1)] = '+';
            }
            else
            {
                screen[i+z*(WIDTH+1)] = '.';
            }
        }   
        z++; 
        if(z == WIDTH)
        {
            screen[z*(WIDTH+1)-1] = '\n';
            screen[z*(WIDTH+1)] = '\0';
        }
        else
        {
            screen[z*(WIDTH+1)-1] = '\n';
        }
    }
    return screen;
}