#include "rational_numbers.h"
#include <stddef.h>
#include <math.h>

int16_t pow_loop(int16_t x, int16_t n)
{
    int16_t res = 1;
    for (int16_t i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
}

int16_t gcd(int16_t a, int16_t b)
{
    a = ( a > 0) ? a : -a;
    b = ( b > 0) ? b : -b;

    while (b != 0)
    {
       int16_t tmp = b;
       b = a % b;
       a = tmp;
    }
    return a;
}

rational_t add(rational_t r1, rational_t r2)
{
    return reduce((rational_t){.numerator = (r1.numerator*r2.denominator + r2.numerator*r1.denominator), .denominator = (r1.denominator*r2.denominator)});
}

rational_t subtract(rational_t r1, rational_t r2)
{
    return reduce((rational_t){.numerator = (r1.numerator*r2.denominator - r2.numerator*r1.denominator), .denominator = (r1.denominator*r2.denominator)});
}

rational_t multiply(rational_t r1, rational_t r2)
{
    return reduce((rational_t){.numerator = (r1.numerator*r2.numerator), .denominator = (r1.denominator*r2.denominator)});
}

rational_t divide(rational_t r1, rational_t r2)
{
    return reduce((rational_t){.numerator = r1.numerator*r2.denominator, .denominator = r2.numerator*r1.denominator});
}

rational_t absolute(rational_t r)
{
    int16_t a = r.numerator;
    int16_t b = r.denominator;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    return reduce((rational_t){.numerator = a, .denominator = b});
}

rational_t exp_rational(rational_t r, int16_t n)
{
    if (n >= 0)
    {
        return reduce((rational_t){.numerator = pow_loop(r.numerator, n), .denominator = pow_loop(r.denominator, n)});
    }
    else
    {
        int16_t m = -n;
        return reduce((rational_t){.numerator = pow_loop(r.denominator, m), .denominator = pow_loop(r.numerator, m)});
    }
}

float exp_real(int16_t x, rational_t r)
{
    return powf(x, (float)(r.numerator)/(r.denominator));
}

rational_t reduce(rational_t r)
{
    int16_t div = gcd(r.numerator, r.denominator);
    rational_t res = (rational_t){.numerator = (r.numerator)/div, .denominator = (r.denominator)/div};
    if ((res.denominator) < 0)
    {
        res.numerator = -(res.numerator);
        res.denominator = -(res.denominator);
    }
    return res;
}