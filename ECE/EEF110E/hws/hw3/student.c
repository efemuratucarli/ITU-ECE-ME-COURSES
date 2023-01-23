// ONLY UPLOAD THIS FILE
#include <stdio.h>
#include <math.h>

int calculator(char* str) //DO NOT CHANGE arguments, name and return type
{
    //implementation goes here
    int i = 0;
    int operation = 2;
    int result = 0;
    int terminal = -1;
    while(str[i] != '\0')
    {
        i++;
    }
    for(int z = 0; z < i ; z++)
    {
        if(str[z] > 47 && str[z] < 58 && (str[z+1] < 48 || str[z+1] > 57) && z > terminal)
        {
            if(operation == 1)
            {
                result = result + (str[z] - '0');
                operation = 2;
            }
            else if(operation == 0)
            {
                result = result - (str[z] - '0');
                operation = 2;
            }
            else
            {
                result = result + str[z] - '0';
            }
        }
        else if(str[z] > 47 && str[z] < 58 && z > terminal) 
        {
            for(int k = z+1; k < i; k++)
            {
                 if(str[k] > 47 && str[k] < 58 && (str[k+1] < 48 || str[k+1] > 57))
                 {
                    double a = 0;
                    for(int bk = k; bk >= z; bk--)
                    {
                        if(operation == 0)
                        {
                            result = result - ((str[bk] - '0')*(pow(10,a)));
                        }
                        else
                        {
                            result = result + ((str[bk] - '0')*(pow(10,a)));
                        }
                        a++;
                    }
                    terminal = k;
                    break;
                 }
            }
        }
        else if(str[z] == '+')
        {
            operation = 1;
        }
        else if(str[z] == '-')
        {
            operation = 0;
        }
        else
        {
            continue;
        }
    }
    return result;
}

float integrate_simpson(float a,float b)//DO NOT CHANGE arguments, name and return type
{
    //implementation goes here
    float result = 0;
    result = ((b-a)/6)*(sin(a) + 4*sin((a+b)/2) + sin(b));
    return result;
}

float integrate_numeric(float a,float b)//DO NOT CHANGE arguments, name and return type
{
    //implementation goes here
    float dx = (b-a)/99;
    float result = 0;
    for(int i = 1; i <= 99 ; i++)
    {
        result = sin(a+(dx*(i)))*dx + result;
    }
    return result;
}

void grade()//DO NOT CHANGE arguments, name and return type
{
    //implementation goes here
    FILE *fpointer;
    FILE *foutputpointer;
    char buffer[8];
    char *flag = 0;
    float midterm_note = 0.0;
    float final_note = 0.0;
    float average = 0.0;
    float midterm_total_average = 0.0;
    float final_total_average = 0.0;
    float mean_of_averages = 0.0;
    int n = 0;
    fpointer = fopen("input.txt","r");
    foutputpointer = fopen("output.txt","w");
    while (!feof(fpointer))
    {
        flag = fgets(buffer, 8, fpointer);
        if (flag != NULL)
        {
            n++;
            int i = 0 ;
            while(buffer[i] != '\0')
            {   
                if(buffer[i] == ',')
                {
                    int a = 0;
                    for(int k=i-1; k >= 0 ; k--)
                    {
                     midterm_note = (buffer[k] - '0')*pow(10,a) + midterm_note;
                     a++;
                    } 
                    fprintf(foutputpointer,"%.2f,",midterm_note);
                    average = average + 0.4*midterm_note;
                    midterm_total_average = midterm_total_average + midterm_note;           
                    midterm_note = 0;
                }
                else if ((buffer[i+1] == '\n' || buffer[i+1] == '\0') && buffer[i] >= '0' && buffer[i] <= '9')
                {
                    int k = i;
                    int a = 0;
                    while(buffer[k] != ',')
                    {
                        final_note = (buffer[k] - '0')*pow(10,a) + final_note;
                        a++;
                        k--;
                    }      
                    fprintf(foutputpointer,"%.2f|",final_note);
                    average = average + 0.6*final_note;
                    mean_of_averages = mean_of_averages + average;
                    final_total_average = final_total_average + final_note;   
                    fprintf(foutputpointer,"%.2f|",average);
                    if(average <= 29 && average >= 0)
                    {
                        fprintf(foutputpointer,"FF\n");
                    }
                    else if(average <= 41 && average >= 30)
                    {
                        fprintf(foutputpointer,"DD\n");
                    }
                    else if(average <= 53 && average >= 42)
                    {
                        fprintf(foutputpointer,"DC\n");
                    }
                    else if(average <= 64 && average >= 54)
                    {
                        fprintf(foutputpointer,"CC\n");
                    }
                    else if(average <= 76 && average >= 65)
                    {
                        fprintf(foutputpointer,"CB\n");
                    }
                    else if(average <= 87 && average >= 77)
                    {
                        fprintf(foutputpointer,"BB\n");
                    }
                    else if(average <= 93 && average >= 88)
                    {
                        fprintf(foutputpointer,"BA\n");
                    }
                    else if(average <= 100 && average >= 94)
                    {
                        fprintf(foutputpointer,"AA\n");
                    }

                    if(buffer[i+1] == '\0')
                    {
                        fprintf(foutputpointer,"-----------------------------------\n");
                        fprintf(foutputpointer,"%.2f,",midterm_total_average/(n));
                        fprintf(foutputpointer,"%.2f|",final_total_average/(n));
                        fprintf(foutputpointer,"%.2f|",mean_of_averages/(n));
                    }
                    final_note = 0;
                    average = 0;
                    break;
                }
                i++;
            }
        }
    }
}