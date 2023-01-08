#include <math.h>

float exponetial_method(int n)
{
    return exp(0.5*log(n));
}

float babylonian_method(int n)
{
    float x = n;
    float y = 1;
    float e = 0.000001; /* e decides the accuracy level*/

    while (x-y > e)
    {
        x = (x+y)/2;
        y = n/x;
    }
    return x;
}