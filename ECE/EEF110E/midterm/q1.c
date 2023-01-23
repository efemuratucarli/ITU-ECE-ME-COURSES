// DO NOT SUBMIT THIS FILE USE FOR TESTING ONLY
#include <stdio.h>

void sort_q1(int[],int); //DO NOT IMPLEMENT HERE - GOTO student.c

int main()
{
    int arr1[] = {4,0,0,3,0,4,5,0,6,7,0,0,0,0};
    int len = sizeof(arr1)/sizeof(arr1[0]);
    printf("input:  ");
    for(int i = 0; i < len; i++)
    {
        printf("%3d", arr1[i]);
    } 
    printf("\n");
    sort_q1(arr1,len); 
    printf("output: ");
    for(int i = 0; i < len; i++)
    {
        printf("%3d", arr1[i]);
    } 
    printf("\n");

}