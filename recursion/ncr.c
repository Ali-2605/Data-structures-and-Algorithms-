#include <stdio.h>
#include <stdlib.h>


int C(int n, int r)
{
    if(n < r)
    {
        printf("Incorrect answer\n");
        return -1;
    }
    if(n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return C(n - 1, r - 1) + C(n - 1, r);
    }
}


int main()
{
    int n = 4, r = 2;
    printf("%dC%d = %d\n", n, r, C(n, r));
}
