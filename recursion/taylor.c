#include <stdio.h>
#include <stdlib.h>

double taylor1(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = taylor1(x, n - 1);
        p *= x;
        f *= n;
        return r + p/f;

    }
}

double taylor2(double x, double n)
{
    static double s = 1;
    if(n == 0)
    {
        return s;
    }
    s = 1 + x/n * s;
    return taylor2(x ,n - 1);
}

double taylor3(int x, int n)
{
    double s = 1;
    double num = 1;
    double den = 1;
    for(int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    int x = 1;
    int n = 10;
    printf("%lf\n by recursion: ", taylor1(x, n));
    printf("%lf\n by simpiliar recursion: ", taylor2(x, n));
    printf("%lf\n by loop: " , taylor3(x, n));
}