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
        A = new int[n];   
    }

    void set(int i, int j, int x)
    {
        if(i == j)
        {
            A[i] = x;
        }
    }

    int get(int i, int j)
    {
        if(i == j)
            return A[i];

        else
            return 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    printf("%d ", A[i]);
                else
                    printf("%d ", 0);
            }
            printf("\n");
        }
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
    x.set(1, 1, 4);
    x.set(2, 2, 5);
    x.set(3, 3, 6);

    x.display();

    printf("%d \n", x.get(3, 3));
    return 0;
}