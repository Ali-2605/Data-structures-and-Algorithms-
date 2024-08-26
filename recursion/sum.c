#include <stdio.h>
#include <stdlib.h>


int sum1(int n)
{
    if(n == 0)
        return 0;
    else
        return sum1(n - 1) + n;
}

int sum2(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int sum3(int n)
{
    return (n * (n + 1))/ 2;
}

int main()
{
    int n = 5;
    printf("Sum by recursion = %d", sum1(n));
    printf("\n");
    printf("Sum by loop = %d", sum2(n));
    printf("\n");
    printf("Sum by formula = %d", sum3(n));
    printf("\n");
    return 0;
}