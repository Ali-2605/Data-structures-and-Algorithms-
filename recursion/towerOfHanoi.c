#include <stdio.h>
#include <stdlib.h>

int num = 0;
void hanoi(int n, int a, int b, int c)
{
    if(n > 0)
    {
        hanoi(n - 1, a, c, b);
        printf("Move %d to %d\n", a, c);
        num++;
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n = 4;
    hanoi(n, 1, 2, 3);
    printf("Number of times = %d\n", num);
    return 0;
}