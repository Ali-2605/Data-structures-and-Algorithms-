#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

class Array
{
private:
    int *A;
    int size;
    int length;

    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    // Constructor with initializer list
    Array(std::initializer_list<int> init_list)
    {
        size = init_list.size();
        length = size;
        A = new int[size];

        int i = 0;
        for (int value : init_list)
        {
            A[i++] = value;
        }
    }

    // Constructor for custom initialization similar to C struct initialization
    Array(const int arr[], int sz, int len)
    {
        size = sz;
        length = len;
        A = new int[size];

        for (int i = 0; i < length; i++)
        {
            A[i] = arr[i];
        }
    }

    ~Array()
    {
        delete[] A;
    }

    void display() const
    {
        std::cout << "Elements are: \n";
        for (int i = 0; i < length; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    void append(int num)
    {
        if (length < size)
        {
            A[length++] = num;
        }
        else
        {
            std::cout << "Array is full" << std::endl;
        }
    }

    void insert(int index, int num)
    {
        if (index >= 0 && index <= length && length < size)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = num;
            length++;
        }
    }

    int delete1(int index)
    {
        int x = -1;
        if (index >= 0 && index < length)
        {
            x = A[index];
            for (int i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            length--;
        }
        else
        {
            std::cout << "Index is out of bounds" << std::endl;
        }
        return x;
    }

    int linearSearch(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(A[i], A[0]);
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int key)
    {
        int low = 0;
        int high = length - 1;

        while (low <= high)
        {
            int middle = (low + high) / 2;

            if (key == A[middle])
            {
                return middle;
            }
            else if (key < A[middle])
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        return -1;
    }

    int get(int index) const
    {
        if (index >= 0 && index < length)
        {
            return A[index];
        }
        return -1;
    }

    void set(int index, int x)
    {
        if (index >= 0 && index < length)
        {
            A[index] = x;
        }
        else
        {
            std::cout << "Invalid index" << std::endl;
        }
    }

    int max() const
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }

    int min() const
    {
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
            }
        }
        return min;
    }

    int sum() const
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }

    int avg() const
    {
        return sum() / length;
    }

    void reverse()
    {
        for (int i = 0; i < length / 2; i++)
        {
            swap(A[i], A[length - i - 1]);
        }
    }

    void leftShift()
    {
        for (int i = 0; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        A[length - 1] = 0;
    }

    void leftReverse()
    {
        int x = A[0];
        for (int i = 0; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        A[length - 1] = x;
    }

    void rightShift()
    {
        for (int i = length - 1; i > 0; i--)
        {
            A[i] = A[i - 1];
        }
        A[0] = 0;
    }

    void rightReverse()
    {
        int x = A[length - 1];
        for (int i = length - 1; i > 0; i--)
        {
            A[i] = A[i - 1];
        }
        A[0] = x;
    }

    void insertSort(int x)
    {
        if (length == size)
        {
            std::cout << "Array is full" << std::endl;
            return;
        }
        int i = length - 1;
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }

    bool isSorted() const
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void rearrange()
    {
        int i = 0, j = length - 1;
        while (i < j)
        {
            while (A[i] < 0)
                i++;
            while (A[j] >= 0)
                j--;
            if (i < j)
            {
                swap(A[i], A[j]);
            }
        }
    }

    void merge(const Array &arr1, const Array &arr2)
    {
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.A[i] < arr2.A[j])
            {
                A[k++] = arr1.A[i++];
            }
            else
            {
                A[k++] = arr2.A[j++];
            }
        }
        while (i < arr1.length)
        {
            A[k++] = arr1.A[i++];
        }
        while (j < arr2.length)
        {
            A[k++] = arr2.A[j++];
        }
        length = k;
    }

    void unionArr(const Array &arr1, const Array &arr2)
    {
        if (arr1.isSorted() && arr2.isSorted())
        {
            int i = 0, j = 0, k = 0;
            while (i < arr1.length && j < arr2.length)
            {
                if (arr1.A[i] < arr2.A[j])
                {
                    A[k++] = arr1.A[i++];
                }
                else if (arr1.A[i] > arr2.A[j])
                {
                    A[k++] = arr2.A[j++];
                }
                else
                {
                    A[k++] = arr2.A[j++];
                    i++;
                }
            }
            while (i < arr1.length)
            {
                A[k++] = arr1.A[i++];
            }
            while (j < arr2.length)
            {
                A[k++] = arr2.A[j++];
            }
            length = k;
        }
    }

    void intersectionArr(const Array &arr1, const Array &arr2)
    {
        if (arr1.isSorted() && arr2.isSorted())
        {
            int i = 0, j = 0, k = 0;
            while (i < arr1.length && j < arr2.length)
            {
                if (arr1.A[i] < arr2.A[j])
                {
                    i++;
                }
                else if (arr1.A[i] > arr2.A[j])
                {
                    j++;
                }
                else
                {
                    A[k++] = arr2.A[j++];
                    i++;
                }
            }
            length = k;
        }
    }

    void differenceArr(const Array &arr1, const Array &arr2)
    {
        if (arr1.isSorted() && arr2.isSorted())
        {
            int i = 0, j = 0, k = 0;
            while (i < arr1.length && j < arr2.length)
            {
                if (arr1.A[i] < arr2.A[j])
                {
                    A[k++] = arr1.A[i++];
                }
                else if (arr1.A[i] > arr2.A[j])
                {
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            while (i < arr1.length)
            {
                A[k++] = arr1.A[i++];
            }
            length = k;
        }
    }

    void findMissing()
    {
        if(isSorted())
        {
            int j = A[0];
            int x = 0;
            for(int i = 0; i < length; i++)
            {
                if(A[i] != j) 
                {
                    x = 1;
                    printf("Missing number is: %d\n", j);
                    j = A[i];
                    j++;
                }
                else
                {
                    j++;
                }
            }
            if(!x)
            {
                printf("No missing numbers in the list\n");
            }
            return;
        }
        else
        {
            int h = max();
            int l = min();
            printf("h = %d l = %d\n", h , l);
            
            int arr2[h];
            arr2[0] = l;
            for(int i = 0; i < length; i++)
            {
                int x = A[i];
                arr2[A[i]] = 1;
            }
            for(int j  = l; j <= h; j++)
            {
                if(arr2[j] == 0)
                {
                    printf("Missing number is %d\n", j);
                }
                else
                    printf("%d\n", arr2[j]);
            }
        }
    }
};
int main(void)
{
    Array arr1 = {1, 2, 11, 4, 6, 7, 8, 9, 10};
    arr1.display();
    arr1.findMissing();

    // Array arr1(10);
    // arr1.append(10);
    // arr1.append(5);
    // arr1.append(3);
    // arr1.append(7);
    // arr1.append(12);
    // arr1.append(-1);

    // printf("arr1: \n");
    // arr1.display();

    // Array arr2(10);
    // arr2.append(3);
    // arr2.append(7);
    // arr2.append(2);
    // arr2.append(-1);
    // arr2.append(11);

    // printf("arr1: \n");
    // arr2.display();

    // int ch, sz;
    // printf("Enter the size of the Array: ");
    // scanf("%d", &sz);


    // do
    // {
    //     printf("\n");
    //     printf("Menu\n");
    //     printf("1. Insert\n");
    //     printf("2. Delete\n");
    //     printf("3. Search\n");
    //     printf("4. Sum\n");
    //     printf("5. Display\n");
    //     printf("6. Exit\n");

    //     printf("Enter your choice: ");
    //     scanf("%d", &ch);

    //     int x, index;
    //     switch (ch)
    //     {
    //     case 1:
    //         printf("Enter an index: ");
    //         scanf("%d", &index);

    //         printf("Enter an Element you want to insert: ");
    //         scanf("%d", &x);

    //         arr1.insert(index, x);
    //         break;

    //     case 2:
    //         printf("Enter an index: ");
    //         scanf("%d", &index);

    //         x = arr1.delete1(index);
    //         printf("Deleted element is: %d\n", x);

    //         break;

    //     case 3:
    //         printf("Enter element to serach: ");
    //         scanf("%d", &x);

    //         printf("Element index %d", arr1.binarySearch(x));
    //         break;

    //     case 4:
    //         printf("The sum of the list is: %d\n", arr1.sum());
    //         break;

    //     case 5:
    //         arr1.display();
    //         break;
    //     }
    // } while (ch < 6);
    // {
    //     return 0;
    // }

}