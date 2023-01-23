// ONLY UPLOAD THIS FILE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//********* Q1 ************************//
void sort_q1(int arr[],int len)
{
    // implementation goes here
    if(len > 1)
    {
        for(int i = 0; i < len;i++)
        {
            if(arr[i] == 0)
            {
                int indices = i;
                for(int j = i+1; j < len;j++)
                {
                        if(arr[j] != 0)
                        {
                            arr[indices] = arr[j];
                            arr[j] = 0;
                            indices = j;
                        }
                }
            }
        }
    }
}
//********* Q2 ************************//
float checkCollisionAreaPercent(float rect1[4], float rect2[4])
{
    // implementation goes here
   if(rect1[1] > (rect2[1]+rect2[3]) || rect2[1] > (rect1[1]+rect1[3]))
   {
    return 0;
   }
   if(rect1[0] > (rect2[0]+rect2[2]) || rect2[0] > (rect1[0]+rect1[2]))
   {
    return 0;
   }
   
   float horizontal_dist = 0;
   float min_end_point_x = 0;
   float max_starting_point_x = 0; 
   if(rect1[0]+rect1[2] > rect2[0]+rect2[2])
   {
    min_end_point_x = rect2[0]+rect2[2];
   }
   else
   {
    min_end_point_x = rect1[0]+rect1[2];
   }
   if(rect1[0] > rect2[0])
   {
    max_starting_point_x = rect1[0];
   }
   else
   {
    max_starting_point_x = rect2[0];
   }
   horizontal_dist = min_end_point_x - max_starting_point_x;

   float vertical_dist = 0;
   float min_end_point_y = 0;
   float max_starting_point_y = 0;
   if(rect1[1]+rect1[3] > rect2[1]+rect2[3])
   {
    min_end_point_y = rect2[1]+rect2[3];
   }
   else
   {
    min_end_point_y = rect1[1]+rect1[3];
   }
   if(rect1[1] > rect2[1])
   {
    max_starting_point_y = rect1[1];
   }
   else
   {
    max_starting_point_y = rect2[1];
   }
   vertical_dist = min_end_point_y - max_starting_point_y;

   if (vertical_dist == 0 || horizontal_dist == 0)
   {
    return 0;
   }
   float collided_area = vertical_dist * horizontal_dist;
   float remaining_area = (rect1[2]*rect1[3]) + (rect2[2]*rect2[3]) - 2*collided_area;
   return (collided_area / (remaining_area + collided_area))*100;
}
//********* Q3 ************************//
#define ROW_LEN (1+10)
#define CAP 4
char data[ROW_LEN*CAP]={0};
int count=0;

void dump()
{
    // implementation goes here
    for(int i = 0; i <(ROW_LEN*CAP); i++)
    {
        printf("%c",data[i]);
    }
}
void dump_strings()
{
  int z = 0;
  int l = 1;
  int string_count = count;
  while(string_count > 0)
  {
    printf("len:%d | ",(int)data[z]);
    for(int k=0; k < (int)data[z];k++)
    {
        printf("%c",data[l]);
        l++;
    }
    printf("\n");
    l = z + ROW_LEN + 1;
    z = z + ROW_LEN;
    string_count--;
  }
}
int push(char str[],int len)
{
    // implementation goes here
    if(count < CAP && (len-1) <= (ROW_LEN - 1) && len > 1) 
    {
        int z = (ROW_LEN*count);
        data[z] = len-1;
        z++;
        for(int i = 0; i < (len-1);i++)
        {
            data[z] = str[i];
            z++;
        }
        count++;
        return 1;
    }
    return 0;
}
void status()
{
    // implementation goes here
    int z = 0;
    int string_count = count;
    float total_length = 0;
    float total_cap = (ROW_LEN-1)*CAP;
    while(string_count > 0)
    {
        total_length = (int)data[z] + total_length ;
        z = z + ROW_LEN;
        string_count--;
    }
    printf("%.2f%c is used.\n",(total_length/total_cap)*100,37);
}
void pop()
{
    // implementation goes here
    if(count > 0)
    {
        int z = (ROW_LEN*count);
        for(int i = (z-ROW_LEN); i < z;i++)
        {
            data[i] = '.';
        }
        count--;
    }
}
void sort()
{
    // implementation goes here
    if(count > 1)
    {
        for(int i = 0; i < count-1 ; i++)
        {
            for(int j = i+1; j < count; j++)
            {
                int length1 = (int)data[i*ROW_LEN];
                int length2 = (int)data[j*ROW_LEN];
                if(length1 >= length2)
                {
                    int indice1 = i*ROW_LEN + 1;
                    int indice2 = j*ROW_LEN + 1;
                    for(int s = 0 ; s <= length2 ; s++)
                    {
                        if(data[indice2] < data[indice1])
                        {
                            int indice3 = i*ROW_LEN;
                            int indice4 = j*ROW_LEN;
                            char temp[11] = {0};
                            for(int m = 0; m < ROW_LEN; m++)
                            {
                                temp[m] = data[indice3];
                                data[indice3] = data[indice4];
                                data[indice4] = temp[m];
                                indice3++;
                                indice4++;
                            }
                        }
                        else if (data[indice2] == data[indice1])
                        {
                            indice1++;
                            indice2++;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    int indice1 = i*ROW_LEN + 1;
                    int indice2 = j*ROW_LEN + 1;
                    for(int s = 0 ; s <= length1 ; s++)
                    {
                        if(data[indice2] < data[indice1])
                        {
                            int indice3 = i*ROW_LEN;
                            int indice4 = j*ROW_LEN;
                            char temp[11] = {0};
                            for(int m = 0; m < ROW_LEN; m++)
                            {
                                temp[m] = data[indice3];
                                data[indice3] = data[indice4];
                                data[indice4] = temp[m];
                                indice3++;
                                indice4++;
                            }
                        }
                        else if (data[indice2] == data[indice1])
                        {
                            indice1++;
                            indice2++;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }   
}