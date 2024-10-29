#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int n;
    int A[10];
};

void set(struct matrix *x,int i,int j,int num)
{
    if(i == j)
    {
        x->A[i] = num;
    }

}

int get(struct matrix *x,int i,int j)
{
    if(i == j)
        return x->A[i];
    else
        return 0;
}

void Display(struct matrix *x)
{
    for(int i = 0; i < (x->n); i++)
    {
        for(int j = 0; j < (x->n); j++)
        {
            if(i == j)
            printf("%d ", x->A[i]);
            else
            printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    struct matrix x;
    x.n = 5;
    set(&x, 0, 0, 1);
    set(&x, 1, 1, 7);
    set(&x, 2, 2, 5);
    set(&x, 3, 3, 6);
    set(&x, 4, 4, 3);
    Display(&x);  
    set(&x, 0, 0, 9);
    printf("--------------------\n");
    Display(&x);

    return 0;
}