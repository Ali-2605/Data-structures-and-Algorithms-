#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int A[5];
    // int B[5] = {1, 2, 3, 4, 5};
    // int C[5] = {1, 2};
    // int D[5] = {0};

    // printf("The list of A includes\n");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf(" %d,\n", A[i]);
    // }

    // printf("The list of B includes\n");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf(" %d,\n", B[i]);
    // }

    // printf("The list of C includes\n");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf(" %d,\n", C[i]);
    // }

    // printf("The list of D includes\n");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf(" %d,\n", D[i]);
    // }

    int *p;

    p =(int *)malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        p[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", p[i]);
    }

    int *q;

    q =(int *)malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;
    free(q);
    
    for(int i = 5; i < 10; i++)
    {
        p[i] = i;
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }
}