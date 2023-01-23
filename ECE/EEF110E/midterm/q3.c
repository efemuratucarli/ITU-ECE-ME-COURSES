#include <stdio.h>

void dump();
void dump_strings();
int push(char[],int);
void status();
void pop();
void sort();

int main()
{
    char test[]="trabzon";
    char test2[]="denizli";
    char test3[]="adana";
    char test4[]="zonguldak";
    char test5[]="bolu";

    push(test, sizeof(test)/sizeof(test[0]));
    push(test2, sizeof(test2)/sizeof(test2[0]));
    push(test3, sizeof(test3)/sizeof(test3[0]));
    push(test4, sizeof(test4)/sizeof(test4[0]));
    push(test5, sizeof(test5)/sizeof(test5[0]));
    dump_strings(); sort(); 
    printf("\n");
    dump_strings(); status(); pop(); pop(); pop(); dump();

    return 0;
}

