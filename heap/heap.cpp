#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void insert(int A[], int n)
{
    int i, temp = A[n];
    i = n;
    while (i > 1 && temp > A[i / 2])  // Fix the heap insertion
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int delete_heap(int A[], int n)
{
    int i, temp, j;
    int val = A[1];
    A[1] = A[n];
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (A[j + 1] > A[j] && j + 1 <= n - 1)  // Fix comparison check
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = i * 2;
        }
        else break;
    }
    A[n] = val;
    return val;
}

void createHeap(int A[], int n)
{
    for (int i = 2; i <= n; i++)  // Fix to loop through from 2 to n
        insert(A, i);
}

void display(int A[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d, ", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};  // Keep the 1-based index assumption
    createHeap(A, 7);
    display(A, 7);

    return 0;
}
