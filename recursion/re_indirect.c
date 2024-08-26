#include <stdio.h>
#include <stdlib.h>

int n = 0;

void funB(int x);
void funA(int x)
{
    if(x > 0)
    {
        n++;
        printf("%d ", x);
        funB(x - 1);       
    }
}

void funB(int x)
{
    if (x > 1)
    {
        n++;
        printf("%d ", x);
        funA(x/2);     
    }
}

int main()
{
    int x = 20;
    funA(x);
    printf("\n");
    printf("%d\n", n);
    return 0;
}