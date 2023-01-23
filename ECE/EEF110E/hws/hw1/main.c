//***************************************
//** DO NOT SUBMIT THIS FILE
//***************************************
#include <stdio.h>
#include <math.h>

/*   Q1 */
void generate(int);
/*   Q2 */
double pol(double x)
{
    return (pow(x,2)) - 16;
}; //implementation may go here
double dpol(double x)
{
    return 2*(pow(x,1));
    }//implementation may go here
double iterate(double);

int main()
{
    generate(6);
    printf("%lf",iterate(2));
    /*   Q1 */
    // some code to test the function(s)
    /*   Q2 */
    // some code to test the function(s)

    return 0;
}