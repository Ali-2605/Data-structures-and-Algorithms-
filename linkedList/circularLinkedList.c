#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}* head;

void create(int A[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void displayR(struct Node *p)
{
    static int flag = 0;
    if(p != head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        displayR(p->next);
    }
    flag = 0;
}

int length(struct Node *p)
{
    int length = 0;
    do
    {
        length++;
        p = p->next;
    } while(p != head);
    return length;
}

void insert(struct Node *p, int index, int num)
{
    if(index > length(p) || index < 0)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *t;
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = num;
        if(head == NULL)
        {
            head = t;
            head ->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = num;
        t->next = p->next;
        p->next = t;
    }
}

int delete(struct Node *p, int index)
{
    if(index > length(p) || index < 0)
    {
        printf("Invalid position\n");
        return -1;
    }

    struct Node *q;
    int x;
    if(index == 0)
    {
        while(p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if(p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }

    else
    {
        for(int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int sum(struct Node *p)
{
    int sum = 0;
    do
    {
        sum += p->data;
        p = p->next;
    } while(p != head);
    return sum;
}


int max(struct Node *p)
{
    int max = p->data;
    do
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    } while(p != head);
    return max;
}

int search(struct Node *p, int key)
{
    struct Node *q = NULL;

    do
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return 1;
        }
        q = p;
        p = p->next;
    } while(p != head);
    return 0;
}

void sortedInsert(struct Node * p, int num) 
{
    struct Node *t, *q = NULL;
    t =(struct Node *)malloc(sizeof(struct Node));
    t->data = num;
    t->next = NULL;
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        while(p && p->data < num)
        {
            q = p;
            p = p->next;
        }
        if(p == head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int isSorted(struct Node * p)
{
    int x = -65536;
    do
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
    } while(p != head);
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

    do
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
    } while(q != head);
}

void reverseElements(struct Node *p)
{
    int i = 0;
    int x = length(p);
    int A[x];

    do
    {
        A[i] = p->data;
        p = p->next;
        i++;
    } while(p != head);

    p = head;
    i--;

    do
    {
        p->data = A[i];
        p = p->next;
        i--;
    } while(p != head);
}

void reverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    do
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } while(p != head);
    head->next = q;
    head = q;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(head);

    printf("Sum: %d\n", sum(head));
    printf("Max: %d\n", max(head));

    printf("Is the number 9 in the list: \n");
    printf("%s\n", search(head, 9) ? "Yes" : "No");

    // reverseElements(head);
    // display(head);

    // reverseLinks(head);
    // display(head);

    // insert(head, 2, 6);
    // display(head);

    // printf("%d \n", length(head));

    // displayR(head);
    // printf("\n");
}