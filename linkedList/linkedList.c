#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}* first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t; 
        last = t;
    }
}

void create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t; 
        last = t;
    }
}


void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void displayR(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        displayR(p->next);
    }

    else
    {
        printf("\n");
    }
}


int length(struct Node *p)
{
    int length = 0;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

int lengthR(struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    return lengthR(p->next) + 1;
}

int sum(struct Node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumR(struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    return sumR(p->next) + p->data;
}

int max(struct Node *p)
{
    int max = p->data;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int maxR(struct Node *p)
{
    int max = 0;
    if(p == NULL)
    {
        return 0;
    }

    max = maxR(p->next);
    return p->data < max ? max : p->data;
}

int search(struct Node *p, int key)
{
    struct Node *q = NULL;

    while(p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return 1;
        }
        q = p;
        p = p->next;
    }

    return 0;
}

int searchR(struct Node *p, int key)
{
    if(p == NULL)
    {
        return 0;
    }

    else if(key == p->data)
    {
        return 1;
    }

    else
    {
        return searchR(p->next, key);
    }
}

void insert(struct Node * p, int index, int num) 
{
    if(index > length(p) || index < 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *q = NULL;
    q =(struct Node *)malloc(sizeof(struct Node));
    q->data = num;
    p = first;
    if(index == 0)
    {
        q->next = first;
        first = q;
    }

    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
}


void sortedInsert(struct Node * p, int num) 
{
    struct Node *t, *q = NULL;
    t =(struct Node *)malloc(sizeof(struct Node));
    t->data = num;
    t->next = NULL;
    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data < num)
        {
            q = p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete(struct Node * p, int index)
{
    if(index > length(p) || index < 0)
    {
        printf("Invalid position\n");
        return -1;
    }

    struct Node *q = NULL;
    int x = -1;

    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node * p)
{
    int x = -65536;
    while(p != NULL)
    {
        if(x > p->data)
        {
            return 0;
        }
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return 1;
}

void deleteDublicates(struct Node * p)
{
    if(p == NULL)
    {
        printf("There is no nodes in the linked List\n");
        return;
    }

    struct Node *q = p->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverseElements(struct Node *p)
{
    int i = 0;
    int x = length(p);
    int A[x];

    while(p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first;
    i--;

    while(p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}

void reverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseLinksR(struct Node * q, struct Node *p)
{
    if(p != NULL)
    {
        reverseLinksR(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concat(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *first, struct Node *second)
{
    struct Node *last;
    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = first;
        second = second->next;
        last->next = NULL;
    }

    while(first != NULL && second != NULL)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if(first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
}

int isLoop(struct Node *f)
{
    struct Node *q, *p;    
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (q != NULL && p != NULL && p != q);

    if(p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int A[] = {1, 5, 6, 7, 10};
    create(A, 5);

    // struct Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    printf("Is it a loop: %s\n", isLoop(first) ? "Yes" : "No");

    // int B[] = {2, 3, 4, 8, 9};
    // create2(B, 5);

    // display(first);
    // display(second);

    // merge(first, second);
    // display(third);

    // concat(first, second);
    // display(third);

    // struct Node *q = NULL;
    // reverseLinksR(q, first);
    // display(first);

    // reverseLinks(first);
    // display(first);


    // reverseElements(first);
    // display(first);


    // deleteDublicates(first);
    // display(first);


    // printf("Deleted: %d\n", delete(first, 2));
    // display(first);


    // printf("Is the linked List sorted: %s\n", isSorted(first) ? "yes" : "no");

    // printf("length of Nodes = %d\n", count(first));
    // printf("lengthR of Nodes = %d\n", countR(first));

    // printf("sum of data in the Nodes = %d\n", sum(first));
    // printf("sumR of data in the Nodes = %d\n", sumR(first));

    // printf("Maximum is: %d\n", max(first));
    // printf("Maximum R is: %d\n", maxR(first));

    // printf("Is the number 5 in the list: \n");
    // printf("%s\n", search(first, 5) ? "Yes" : "No");
    // printf("%s\n", searchR(first, 4) ? "Yes" : "No");

    //insert(first, 2, 11);
    //display(first);

    // sortedInsert(first, 5);
    // display(first);

    // displayR(first);
    return 0;
}