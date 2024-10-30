#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class element
{
public:
    int i;
    int j;
    int k;
};

class sparse
{
private:
    int m;
    int n;
    int num;
    element *e;

public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[this->num];
    }

    ~sparse()
    {
        delete[] e;
    }

    sparse operator+(sparse &s);


    friend istream &operator>>(istream &is, sparse &s);
    friend ostream &operator<<(ostream &os, const sparse &s);
};

istream &operator>>(istream &is, sparse &s)
{
    for (int i = 0; i < s.num; i++)
    {
        cout << "Enter " << i + 1 << " non-zero element (row, column, value): ";
        is >> s.e[i].i >> s.e[i].j >> s.e[i].k;
    }
    return is;
}

ostream &operator<<(ostream &os, const sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (k < s.num && s.e[k].i == i && s.e[k].j == j)
            {
                os << s.e[k++].k << " ";
            }
            else
            {
                os << "0 ";
            }
        }
        os << endl;
    }
    return os;
}

sparse sparse::operator+(sparse &s)
{
    int i = 0, j = 0, k = 0;
    sparse *sum = new sparse(m, n, num + s.num);

    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i)
        {
            sum->e[k++] = e[i++];
        }
        else if (e[i].i > s.e[j].i)
        {
            sum->e[k++] = s.e[j++];
        }
        else
        {
            if (e[i].j < s.e[j].j)
            {
                sum->e[k++] = e[i++];
            }
            else if (e[i].j > s.e[j].j)
            {
                sum->e[k++] = s.e[j++];
            }
            else
            {
                sum->e[k] = e[i];
                sum->e[k++].k = s.e[j++].k + e[i++].k;
            }
        }
    }
    
    for (; i < num; i++)
    {
        sum->e[k++] = e[i];
    }
    
    for (; j < s.num; j++)
    {
        sum->e[k++] = s.e[j];
    }

    sum->num = k;
    return *sum;
}



int main()
{
    sparse s1(5, 5, 5);
    sparse s2(5, 5, 5);

    cout << "Input the values for the First Matrix: \n";
    cin >> s1;

    cout << "----------------------------\n";

    cout << "Input the values for the Second Matrix: \n";
    cin >> s2;

    cout << "First Matrix: \n" << s1 << endl;
    cout << "Second Matrix: \n" << s2 << endl;
    
    sparse sum = s1 + s2;
    cout << "Sum Matrix: \n" << sum << endl;

    return 0;
}