#include <stdio.h>
#include <stdlib.h>


int fact1(int n)
{
    if(n == 0)
        return 1;
    else
        return fact1(n - 1) * n;
}

int fact2(int n)
{
    int fact = 1;
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}



int main()
{
    int n = 5;
    printf("fact by recursion = %d", fact1(n));
    printf("\n");
    printf("fact by loop = %d", fact2(n));
    printf("\n");
    return 0;
}