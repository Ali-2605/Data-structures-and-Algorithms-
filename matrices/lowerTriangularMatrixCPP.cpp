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
        A = new int[n * (n + 1) / 2];   
    }

    int equationRowMajor(int i, int j)
    {
        return (i * (i + 1)) / 2 + j;
    }

    int equationColumnMajor(int i, int j)
    {
        return (j * (2 * n - j + 1)) / 2 + (i - j);
    }

    void set(int i, int j, int num)
    {
        if (i >= j)
        {
            A[equationColumnMajor(i, j)] = num;
        }
    }

    int get(int i, int j)
    {
        if (i >= j)
            return A[equationColumnMajor(i, j)];
        else
            return 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    printf("%d ", A[equationColumnMajor(i, j)]);
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }

    void actualDisplay()
    {
        for(int i = 0; i < (n * (n + 1)) / 2; i++)
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
    matrix x(3);

    x.set(0, 0, 1);
    x.set(1, 0, 2);
    x.set(1, 1, 3);
    x.set(2, 0, 4);
    x.set(2, 1, 5);
    x.set(2, 2, 6);
    // x.set(3, 0, 7);
    // x.set(3, 1, 8);
    // x.set(3, 2, 9);
    // x.set(3, 3, 10);
    // x.set(4, 0, 11);
    // x.set(4, 1, 12);
    // x.set(4, 2, 13);
    // x.set(4, 3, 14);
    // x.set(4, 4, 15);

    x.display();
    printf("-----------------\n");
    x.actualDisplay();
    return 0;
}