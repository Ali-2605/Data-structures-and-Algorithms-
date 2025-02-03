#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int num)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->pre = first->next = NULL;
    last = first;

    for(int i = 1; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->pre = last;
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

void insert(struct Node *p, int index, int num)
{
    if(index > length(p) || index < 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *q = NULL;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;

    if(index == 0)
    {
        q->pre = NULL;
        q->next = first;
        first->pre = q;
        first = q;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->pre = p;
        q->next = p->next;
        if(p->next)
        {
            p->next->pre = q;
        }
        p->next = q;
    }
}

int delete(struct Node * p, int index)
{
    if(index > length(p) || index < 1)
    {
        printf("Invalid position\n");
        return -1;
    }

    struct Node *q = NULL;
    int x = -1;

    if(index == 1)
    {
        first = first->next;
        if(first != NULL)
        {
            first->pre = NULL;
        }

        x = first->data;
        free(q);
    }
    else
    {
        for(int i = 0; i < index - 1 && p; i++)
        {
            p = p->next;
        }
        p->pre->next = p->next;
        if(p->next)
        {
            p->next->pre = p->pre;
        }
        x = p->data;
        free(p);
    }
    return x;
}

void reverse(struct Node *p)
{
    struct Node *temp;

    while(p != NULL)
    {
        temp = p->next;
        p->next = p->pre;
        p->pre = temp;

        p = p->pre; 
        if(p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(first);
    
    reverse(first);
    display(first);


    // delete(first, 5);
    // display(first);

    // insert(first, 2, 6);
    // display(first);

    // printf("Length = %d\n", length(first));

    return 0;
}