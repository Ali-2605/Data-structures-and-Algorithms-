#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int n; 
    int *A;
};

int equationColumnMajor(int i, int j, int n) {
    return (j * (2 * n - j + 1)) / 2 + (i - j);
}

int equationRowMajor(int i, int j)
{
    return (i * (i + 1)) / 2 + j;
}

void set(struct matrix *x, int i, int j, int num) {
    if(i >= j) {
        x->A[equationColumnMajor(i, j, x->n)] = num;
    }
}

int get(struct matrix *x, int i, int j) {
    if(i >= j)
        return x->A[equationColumnMajor(i, j, x->n)];
    else
        return 0;
}

void display(struct matrix *x) {
    for(int i = 0; i < x->n; i++) {
        for(int j = 0; j < x->n; j++) {
            if(i >= j)
                printf("%d ", x->A[equationColumnMajor(i, j, x->n)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void actualDisplay(struct matrix *x)
{
    for (int i = 0; i < x->n * (x->n + 1) / 2; i++)
    {
        printf("%d ", x->A[i]);
    }
    printf("\n");
}

int main() {
    struct matrix x;
    x.n = 3;
    x.A = (int *)malloc(x.n * (x.n + 1) / 2 * sizeof(int)); 

    set(&x, 0, 0, 1);
    set(&x, 1, 0, 2);
    set(&x, 1, 1, 3);
    set(&x, 2, 0, 4);
    set(&x, 2, 1, 5);
    set(&x, 2, 2, 6);

    display(&x);
    printf("--------------------\n");
    actualDisplay(&x);

    free(x.A); 
    return 0;
}
