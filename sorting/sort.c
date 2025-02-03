#include <stdio.h>
#include <limits.h>


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
}


void bubbleSort(int A[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

void insertSort(int A[], int n)
{
    int j;
    for(int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;
        for(;j > -1 && A[j] > x; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }
}




void selectionSort(int A[], int n)
{
    int k;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = k = i; j < n; j++)
        {
            if(A[j] < A[k])
            {
                k = j;
            }
        }
        swap(&A[k], &A[i]);
    }
}

int partation(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j) swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = partation(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

void mergeSort(int A[], int B[], int n, int m)
{
    int i, j, k;
    i = j = k = 0;
    int C[100];
    while(i < n && j < m)
    {
        if(A[i] <= B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    if(i < n)
    {
        while(i < n) 
            C[k++] = A[i++];
    }
    else
    {
        while(j < m) 
            C[k++] = B[j++];
    }
    display(C, 20);
}

void mergeSort2(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;

    int B[h + 1];
    while(i <= mid && j <= h)
    {
        if(A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    if(i <= mid)
    {
        while(i <= mid) 
            B[k++] = A[i++];
    }
    else
    {
        while(j <= h) 
            B[k++] = A[j++];
    }
    for(int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void ImergeSort(int A[], int n)
{
    int l, mid, h;
    int p;
    for(p = 2; p <= n; p = p*2)
    {
        for(int i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeSort2(A, l, mid, h);
        }
    }
    if(p / 2 < n)
        mergeSort2(A, 0, p/2 - 1, n);
}

void RmergeSort(int A[], int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l + h) / 2;
        RmergeSort(A, l, mid);
        RmergeSort(A, mid + 1, h);
        mergeSort2(A, l, mid, h);
    }
}

int getMax(int A[], int n)
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    int max = getMax(A, n);
    int C[max + 1];
    for(int i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    int i, j;
    i = j = 0;
    while(i < max + 1)
    {
        if(C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else 
        {
            i++;
        }
    }
}

void shellSort(int A[],int n)
{
    int j, temp;

    for(int gap = n/2; gap >= 1; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while(j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }

}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    //int B[] = {5, 9};

    int n = sizeof(A) / sizeof(A[0]);
    //bubbleSort(A, n);
    //insertSort(A, n);
    //selectionSort(A, n);
    //quickSort(A, 0, n - 1);
    //int m = sizeof(B) / sizeof(B[0]);
    //mergeSort(A, B, n, m);
    //display(A, n);
    //ImergeSort(A, n);
    //countSort(A, n);
    shellSort(A, n);
    display(A, n);
}