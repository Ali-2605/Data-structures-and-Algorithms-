#include <stdio.h>
#include <stdlib.h>

int n = 0;

void fun(int x)
{
    if(x > 0)
    {
        n++;
        printf("%d ", x);
        fun(x - 1);       
        fun(x - 1);
    }
}

int main()
{
    int x = 3;
    fun(x);
    printf("\n");
    printf("Number of recursions: %d\n", n);
    return 0;
}