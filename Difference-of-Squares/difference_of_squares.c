long square_of_sum(long n)
{
    return (((n*(n+1))/2)*((n*(n+1))/2));
}

long sum_of_squares(long n)
{
    return ((n*(n+1)*(2*n+1))/6);
}

long difference_of_squares(long n)
{
    return (square_of_sum(n) - sum_of_squares(n));
}