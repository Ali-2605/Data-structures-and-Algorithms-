#include <stdio.h>
#include <stdlib.h>

int f[10];
int fib(int n)
{
    if(n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if(f[n-2] == -1)
        {
            f[n-2] = fib(n-2);
        }
        if(f[n-1] == -1)
        {
            f[n-1] = fib(n-1);  
        }

        return f[n-2] + f[n-1];
    }
}

int main()
{
    int n = 7;
    for(int i = 0; i < 10; i++)
    {
        f[i] = -1;
    }
    printf("Fib for %d of n is: %d\n", n, fib(n));
}