//***************************************
//** DO NOT SUBMIT THIS FILE
//***************************************
#include <stdio.h>

void mem_dump(); //do not change this line
void mat_dump(); //do not change this line
void mat_push(int m,int n,float* data); //do not change this line
void mat_pop(); //do not change this line
void mat_add(); //do not change this line
void mat_substract(); //do not change this line

int main()
{
   

    float mat2 [4]={1 ,2 ,3,4};
    mat_push (2 ,2 ,& mat2 [0]) ;
    float mat [4]={2 ,2 ,2 ,2};
    mat_push (2 ,2 ,& mat [0]) ;
    mat_add();
    mat_dump();
    mem_dump();
    // and various different tests
    return 0;
}