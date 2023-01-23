// DO NOT SUBMIT THIS FILE USE FOR TESTING ONLY
#include <stdio.h>
#include <math.h>

float checkCollisionAreaPercent(float *, float *);//DO NOT IMPLEMENT HERE - GOTO student.c

int main()
{
    float R1[4] = {2.2F, 1, 3, 4.4F}, R2[4] = {3, 2, 5.5F, 5};

    printf("Collision Area: %.2f %%", checkCollisionAreaPercent(R1, R2));

    return 0;
}
