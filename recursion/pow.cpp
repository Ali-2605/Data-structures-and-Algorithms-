#include <stdio.h>
#include <stdlib.h>

int num = 0;

int pow1(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return pow1(m, n - 1) * m;
    }
}

int pow2(int m, int n)
{
    int pow = 1;
    for(int i = 1; i <= n; i++)
    {
        pow *= m;
    }
    return pow;
}

int pow3(int m, int n)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return pow3((m * m), n/2);
    else 
        return pow3(m * m, (n-1)/2) * m;
}

int main()
{
    int m = 5;
    int n = 3;
    printf("pow by recursion = %d", pow1(m, n));
    printf("\n");
    printf("pow by loop = %d", pow2(m, n));
    printf("\n");
    printf("pow by simpiliar recursion = %d", pow3(m, n));
    printf("\n");
    printf("the number of ittrations: %d\n", num);
    return 0;
}