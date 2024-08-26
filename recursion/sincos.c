#include <stdio.h>
#include <stdlib.h>

double pow(double m, double n)
{
    int pow = 1;
    for(int i = 1; i <= n; i++)
    {
        pow *= m;
    }
    return pow;
}

double fact(int n)
{
    int fact = 1;
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}


double sin1(double x, int terms) {
    double sin_x = 0.0;
    double num;

    for (int n = 0; n < terms; n++) {

        if(n % 2 == 0)
        {
            num = 1;
        }

        else
        {
            num = -1;
        }
        num *= pow(x, 2 * n + 1) / fact(2 * n + 1);
        sin_x += num;
    }
    return sin_x;
}

double cos1(double x, int terms) {
    double cos_x = 0.0;
    double num;

    for (int n = 0; n < terms; n++) {
        if(n % 2 == 0)
        {
            num = 1;
        }

        else
        {
            num = -1;
        }
        num *= pow(x, 2 * n) / fact(2 * n);
        cos_x += num;
    }
    return cos_x;
}

double re_sin(double x, int n) {
    if (n < 0) 
    {
        return 0.0;
    }
    double num;
    if(n % 2 == 0)
    {
        num = 1;
    }

    else
    {
        num = -1;
    }

    num *= pow(x, 2 * n + 1) / fact(2 * n + 1);
    return num + re_sin(x, n - 1);
}

double re_cos(double x, int n) {
    if (n < 0) 
    {
        return 0.0;
    }
    double num;    
    if(n % 2 == 0)
    {
        num = 1;
    }

    else
    {
        num = -1;
    }
    num *= pow(x, 2 * n) / fact(2 * n);
    return num + re_cos(x, n - 1);
}

int main()
{
    printf("%lf\n", sin1(1, 10));
    printf("%lf\n", cos1(1, 10));
    printf("%lf\n", re_sin(1, 10));
    printf("%lf\n", re_cos(1, 10));
}