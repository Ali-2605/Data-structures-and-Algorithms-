#include <stdio.h>
#include <stdlib.h>

int n = 0;

int fun(int x)
{
    if(x > 100)
    {
        n++;
        return x - 10;
    }
    return fun(fun(x + 11));
}

int main()
{
    int x = 30;
    int r = fun(x);
    printf("%d\n", r);
    printf("Number of recursions: %d\n", n);
    return 0;
}