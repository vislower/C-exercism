#include <stdio.h>

void pythagorean_triplet_naive(int n)
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++)
            {
                if (a < b && b < c && a*a + b*b == c*c && a+b+c == n)
                {
                    printf("Pythagorean triplets : {%d, %d, %d}\n", a, b, c);
                    return;
                }
                
            }
            
        }
            
    }
    printf("No triplets\n");
}

void pythagorean_triplet_two_loops(int n)
{
    // Considering triplets in
    // sorted order. The value
    // of first element in sorted
    // triplet can be at-most < n/3.
    // because a cannot be more than 332. If it is 333, b has to be at least 334 and c at least 335
    // adding up to 1001. So limit a from 1 to 332.
    for (int i = 1; i <= n / 3; i++)
    {
        
        // The value of second element
        // must be less than equal to n/2

        // Also, b must be less than half of 1000-a (since c has to fill the other more-than-half).
        // So the upper bound of b has to be ceil((1000-a)/2) and because a_min = 1 -> (1000-1)/2 = 499.5
        // -> b_max = 499
        for (int j = i + 1; j < n / 2; j++)
        {
            int k = n - i - j;
            if (i * i + j * j == k * k)
            {
                printf("Pythagorean triplets : {%d, %d, %d}\n", i, j, k);
                return;
            }
        }
    }

    printf("No Triplet\n");
}

void pythagorean_triplet_one_loop(int n)
{
    int c = 0;
    int b = 0;

    for (int a = 0; a <= n; a++)
    {
        b = (n*n - 2*a*n)/(2*n - 2*a);
        c = n - a - b;
        if (a*a + b*b == c*c && a < b && b < c)
        {
            printf("Pythagorean triplets : {%d, %d, %d}\n", a, b, c);
            return;
        }
        
    }
    printf("No Triplet\n");
}

int main()
{
    int n = 90000;

    pythagorean_triplet_one_loop(n);

    return 0;
}