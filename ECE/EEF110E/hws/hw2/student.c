//***************************************
//** SUBMIT ONLY THIS FILE
//** DO NOT CHANGE ANYTHING
//** ONLY ADD THE IMPLEMENTATION
//***************************************
#include <stdio.h>

#define MAT_CAP 2 //value may be changed
#define MAT_SIZE_LEN 2 //value may be changed
int mat_count=0;//do not change this line
float mem[(MAT_SIZE_LEN*MAT_SIZE_LEN+2)*MAT_CAP]={0};//do not change this line

void mem_dump()
{
    //implementation goes here
    printf("Memory:\n");
    for(int i = 0; i < sizeof(mem)/sizeof(mem[0]); i++)
    {
        printf("%f ",mem[i]);
    }
    printf("\n");
}

void mat_dump()
{
    int k = 1;
    int count = mat_count;
    int mx = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2);
    int l = 0;
    while(count > 0)
    {
        printf("Matrix :%d\n",k);
        for(int i = 0; i < mem[mx-2];i++)
        {
            for(int i = 0; i < mem[mx-1];i++)
            {
                printf("%f ",mem[l]);
                l++;
            }
            printf("\n");
        }
        count--;
        int kl = (MAT_SIZE_LEN*MAT_SIZE_LEN) - mem[mx-2]*mem[mx-1];
        l = l + 2 + kl;
        k++;
        mx = mx + ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2);
    }
}

void mat_push(int m,int n,float* data)
{
    //implementation goes here
    if ((mat_count < MAT_CAP) && (m*n <= MAT_SIZE_LEN*MAT_SIZE_LEN) && (m > 0) && (n > 0))
    {
        int z = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2)*mat_count;
        for(int i = 0; i < (m*n); i++)
        {
            mem[z] = *(data+i);
            z = z + 1;
        }
    if(m*n < MAT_SIZE_LEN*MAT_SIZE_LEN)
    {
        int kl = MAT_SIZE_LEN*MAT_SIZE_LEN - (m*n);
        mem[z+kl] = m;
        mem[z+kl+1] = n;
        mat_count++;
    }
    else
    {
        mem[z] = m;
        mem[z+1] = n;
        mat_count++;   
    }
    }
    //no capacity more
}

void mat_pop()
{
    if (mat_count > 0)
    {
        int z = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2)*mat_count;
        for(int i = 0; i < MAT_SIZE_LEN*MAT_SIZE_LEN+2; i++)
        {
            mem[z-1] = 0;
            z = z - 1;
        }
        mat_count = mat_count - 1;
    }
}

void mat_add()
{
    if (mat_count >= 2)
    {
        int z = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2)*mat_count;
        int starting_point = z-(2*((MAT_SIZE_LEN*MAT_SIZE_LEN)+2));
        int incr = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2);
        for(int i = 0; i < MAT_SIZE_LEN*MAT_SIZE_LEN; i++)
        {
            mem[starting_point] = mem[starting_point] + mem[starting_point+incr];
            mem[starting_point+incr] = 0;
            starting_point++;
        }
        mem[starting_point+incr] = 0;
        mem[starting_point+incr+1] = 0;
        mat_count--;
    }
}

void mat_substract()
{
    if (mat_count >= 2)
    {
        int z = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2)*mat_count;
        int starting_point = z-(2*((MAT_SIZE_LEN*MAT_SIZE_LEN)+2));
        int incr = ((MAT_SIZE_LEN*MAT_SIZE_LEN)+2);
        for(int i = 0; i < MAT_SIZE_LEN*MAT_SIZE_LEN; i++)
        {
            mem[starting_point] = mem[starting_point] - mem[starting_point+incr];
            mem[starting_point+incr] = 0;
            starting_point++;
        }
        mem[starting_point+incr] = 0;
        mem[starting_point+incr+1] = 0;
        mat_count--;
    }
}