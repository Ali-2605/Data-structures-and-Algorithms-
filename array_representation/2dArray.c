#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10 , 11, 12}}; //in stack

    int *B[3]; //in stack
    B[0] = (int *) malloc(4 * sizeof(int));    //in heap
    B[1] = (int *) malloc(4 * sizeof(int));    //in heap
    B[2] = (int *) malloc(4 * sizeof(int));    //in heap

    int **C;//in stack
    C = (int **) malloc(3 * sizeof(int)); //in heap 
    C[0] = (int *) malloc(4 * sizeof(int)); //in heap
    C[1] = (int *) malloc(4 * sizeof(int)); //in heap
    C[2] = (int *) malloc(4 * sizeof(int)); //in heap

    printf("This is list A:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    int n = 13;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            B[i][j] = n;
            n++;
        }
    }
    printf("\n");

    printf("This is list B:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    int b = 24;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            C[i][j] = b;
            b++;
        }
    }
    printf("\n");

    printf("This is list C:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

}