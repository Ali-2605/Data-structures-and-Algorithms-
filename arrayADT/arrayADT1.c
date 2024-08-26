#include <stdio.h>
#include <stdlib.h>

struct Array 
{
    int *A;
    int size;
    int length;

};

void display(struct Array arr)
{
    printf("Elements are: \n");

    for(int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
};

void append(struct Array *arr)
{
    int num;
    printf("what number to Append to the array: ");
    scanf("%d", &num); 

    arr->A[arr->length] = num;
    arr->length++;
};


void insert(struct Array *arr, int index, int num)
{

    for(int i =arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[index] = num;

    arr->length++;
}

int delete1(struct Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        for(int i = index; i < arr->length; i++)
        {
            if(!x)
                x = arr->A[i];
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
        return x; 
        
    }
    else
    {
        printf("Index is more than the length of the array\n");
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array *arr, int key)
{
    int high = arr->length - 1;
    int low = 0;
    int middle;

    while(low <= high)
    {
        middle = (high + low)/2;

        if (key == arr->A[middle])
        {
            return middle;
        }

        else if(key < arr->A[middle])
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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    else
        return -1;
}

void set(struct Array *arr, int index, int x)
{
     if (index >= 0 && index < arr->length)
        arr->A[index] = x;
    else
        printf("inputed wrong index");
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(max < arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}

int sum(struct Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int avg(struct Array arr)
{
    return sum(arr) / arr.length;
}

void reverse(struct Array *arr)
{
    for(int i = 0; i < arr->length / 2; i++)
    {
        swap(&arr->A[i], &arr->A[arr->length - i - 1]);
    }
}

void leftShift(struct Array *arr)
{
    arr->A[0] = arr->A[1];
    for(int i = 1; i < arr->length; i++)
    {
       arr->A[i] = arr->A[i+1];
    }
}

void leftReverse(struct Array *arr)
{
    int x = arr->A[0];
    arr->A[0] = arr->A[1];
    for(int i = 1; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length - 1] = x;

}

void rightShift(struct Array *arr)
{
    for(int i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

void rightReverse(struct Array *arr)
{
    int x = arr->A[arr->length - 1];
    for(int i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = x;
}

void insertSort(struct Array *arr, int x)
{
    if(arr->length == arr-> size)
    {
        printf("size == length;");
        return;
    }
    int i;
    for(i = arr->length - 1; i >= 0 && arr->A[i] > x; i--)
    {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[i + 1] = x; 
    arr->length++;
}

int isSorted(struct Array arr)
{
    for(int i = 0; i < arr.length - 1; i++)
    {
        if(arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while(i < j)
    {
        while(arr->A[i] < 0)
            i++;
        
        while(arr->A[j] >= 0)
            j--;

        if(i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
    return;
}

void merge(struct Array arr1, struct Array arr2, struct Array *arr3)
{
    int i = 0, j = 0, k = 0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            arr3->A[k] = arr1.A[i];
            k++;
            i++;
        }
        else
        {
            arr3->A[k] = arr2.A[j];
            k++;
            j++;
        }
    }

    for(;i<arr1.length;i++)
    {
        arr3->A[k] = arr1.A[i];
        k++;
    }   

    for(;j<arr2.length;j++)
    {
        arr3->A[k] = arr2.A[j];   
        k++;
    }
}

void unionArr(struct Array arr1, struct Array arr2, struct Array *arr3)
{ 
    if(isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while(i < arr1.length && j < arr2.length)
        {
            if(arr1.A[i] < arr2.A[j])
            {
                arr3->A[k] = arr1.A[i];
                k++;
                i++;
            }
            else if(arr1.A[i] > arr2.A[j])
            {
                arr3->A[k] = arr2.A[j];
                k++;
                j++;
            }
            else
            { 
                arr3->A[k] = arr2.A[j];
                k++;
                j++;
                i++;
            }
        }

        for(;i<arr1.length;i++)
        {
            arr3->A[k] = arr1.A[i];
            k++;
        }   

        for(;j<arr2.length;j++)
        {
            arr3->A[k] = arr2.A[j];   
            k++;
        }
        arr3->length = k;
    }

    else
    {
        int j = 0;
        int i = 0;
        int k = 0;
        while(i < arr1.length && j < arr1.length)
        {
            if(arr1.A[i] == arr2.A[j])
            {
                arr3->A[k] = arr1.A[i];
                k++;
                i++;
                j++;
            }
            else
            {
                arr3->A[k] = arr1.A[i];
                k++;
                i++;
            }
        }
        for(;i<arr1.length;i++)
        {
            arr3->A[k] = arr1.A[i];
            k++;
        }   

        for(;j<arr2.length;j++)
        {
            arr3->A[k] = arr2.A[j];   
            k++;
        }
        arr3->length = k;
    }
}

void intersectionArr(struct Array arr1, struct Array arr2, struct Array *arr3)
{
    if(isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while(i < arr1.length && j < arr2.length)
        {
            if(arr1.A[i] < arr2.A[j])
            {
                i++;
            }
            else if(arr1.A[i] > arr2.A[j])
            {
                j++;
            }
            else
            { 
                arr3->A[k] = arr2.A[j];
                k++;
                j++;
                i++;
            }
        }
        arr3->length = k;
    }
    else
    {
        int k = 0;
        for(int i = 0; i < arr1.length; i++)
        {
            for(int j = 0; j < arr1.length; j++)
            {
                if(arr1.A[i] == arr2.A[j])
                {
                    arr3->A[k] = arr1.A[i];
                    k++;
                }
            }
        }
        arr3->length = k;

    }
}

void differenceArr(struct Array arr1, struct Array arr2, struct Array *arr3)
{
    if(isSorted(arr1) && isSorted(arr2))
    {
        int i = 0, j = 0, k = 0;
        while(i < arr1.length && j < arr2.length)
        {
            if(arr1.A[i] < arr2.A[j])
            {
                arr3->A[k] = arr1.A[i];
                k++;
                i++;
            }
            else if(arr1.A[i] > arr2.A[j])
            {
                arr3->A[k] = arr2.A[j];
                k++;
                j++;
            }
            else
            { 
                j++;
                i++;
            }
        }

        for(;i<arr1.length;i++)
        {
            arr3->A[k] = arr1.A[i];
            k++;
        }   

        arr3->length = k;
    }
    else
    {
        int j = 0;
        int i = 0;
        int k = 0;
        while(i < arr1.length && j < arr1.length)
        {
            if(arr1.A[i] == arr2.A[j])
            {
                i++;
                j++;
            }
            else
            {
                arr3->A[k] = arr1.A[i];
                k++;
                i++;
            }
        }
        for(;i<arr1.length;i++)
        {
            arr3->A[k] = arr1.A[i];
            k++;
        }   

        arr3->length = k;

    }
}


int main(void)
{
    struct Array arr1;

    printf("Enter the size of the Array: ");
    scanf("%d", &arr1.size);

    arr1.A=(int *) malloc(arr1.size * sizeof(int));
    
    int ch;
    do
    {
        printf("\n");
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        int x, index;
        switch(ch)
        {
            case 1: 
                printf("Enter an index: ");
                scanf("%d", &index);

                printf("Enter an Element you want to insert: ");
                scanf("%d", &x);

                insert(&arr1, index, x);
                break;
            
            case 2:
                printf("Enter an index: ");
                scanf("%d", &index);

                x = delete1(&arr1, index);
                printf("Deleted element is: %d", x);

                break;

            case 3:
                printf("Enter element to serach: ");
                scanf("%d", &x);

                printf("Element index %d", binarySearch(&arr1, x));
                break;

            case 4:
                printf("The sum of the list is: %d", sum(arr1));
                break;

            case 5:
                display(arr1);
                break;
                
        }
    } while (ch < 6);
    {
        return 0;
    }

}