#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stdint.h>

typedef struct rational_t
{
    int16_t numerator;
    int16_t denominator;
} rational_t;

int16_t pow_loop(int16_t x, int16_t n);
int16_t gcd(int16_t a, int16_t b);
rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r);
rational_t exp_rational(rational_t r, int16_t n);
float exp_real(int16_t x, rational_t r);
rational_t reduce(rational_t r);


#endif