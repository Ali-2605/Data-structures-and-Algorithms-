#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class matrix
{

private:
    int n;
    int *A;

public:

    matrix(int n)
    {
        this->n = n;
        A = new int[2 * n - 1];   
    }

    void set(int i, int j, int num)
    {
        if (i <= j) 
        { 
            A[j - i] = num; 
        } 
        else if (i > j) 
        { 
            A[n + i - j - 1] = num; 
        } 
    }

    int get(int i, int j)
    {
        if (i <= j) 
        {
            return A[j - i];
        } 
        else if (i > j) 
        {
            return A[n + i - j - 1];
        } 
        else 
            return 0;
    }

    void display()
    {
        int num;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                num = get(i, j);
                printf("%2d ", num);
            }
            printf("\n");
        }
    }

    void actualDisplay()
    {
        for(int i = 0; i < 2 * n - 1; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    ~ matrix()
    {
        delete []A;
    }
};

int main()
{
    matrix x(4);


    x.set(0, 0, 1);
    x.set(0, 1, 2);
    x.set(0, 2, 3);
    x.set(0, 3, 4);

    x.set(1, 0, 5);
    x.set(1, 1, 6);
    x.set(1, 2, 7);
    x.set(1, 3, 8);

    x.set(2, 0, 9);
    x.set(2, 1, 10);
    x.set(2, 2, 11);
    x.set(2, 3, 12);

    x.set(3, 0, 13);
    x.set(3, 1, 14);
    x.set(3, 2, 15);
    x.set(3, 3, 16);
    
    x.display();
    printf("-----------------\n");
    x.actualDisplay();

    return 0;
}