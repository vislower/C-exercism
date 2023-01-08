#include <stdio.h>
#include <string.h>


double pow(double base, double exponent)
{
    double result = 1;
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}

int bin_to_dec(const char str[])
{
    int length = strlen(str);
    int sum = 0;
    for (int i = length - 1, j = 0; i >= 0 && j < length; i--, j++)
    {
        
        if (str[i] != '0' && str[i] != '1')
        {
            printf("Invalid binary string\n");
            return -1;
        }
        
        if (str[i] == '1')
        {
            sum += pow(2, j);
        }
    }
    return sum;
}

int main(void)
{
    char str[] = "101010";

    printf("%d\n", bin_to_dec(str));

    return 0;
}