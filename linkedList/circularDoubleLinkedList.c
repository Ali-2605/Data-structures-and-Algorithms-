#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
}*head;

void create(int A[], int num)
{
    struct Node *t, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->pre = head->next = head; 
    last = head;

    for(int i = 1; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = head;
        t->pre = last; 

        last->next = t;
        head->pre = t; 

        last = t;            
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while(p != head);
    printf("\n");
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

    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = num;

    // Case 1: Inserting into an empty list
    if(head == NULL)
    {
        head = q;
        head->next = head;  // Circular link to itself
        head->pre = head;    // Circular link to itself
    }
    else
    {
        if(index == 0)
        {
            q->pre = head->pre;
            q->next = head;
            head->pre->next = q;
            head->pre = q;
            head = q;
        }
        else
        {
            for(int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }

            q->next = p->next;
            q->pre = p;

            if(p->next != head)
            {
                p->next->pre = q;
            }

            p->next = q;
        }
    }
}

int delete(struct Node *p, int index)
{
    if(index > length(head) || index < 1)
    {
        printf("Invalid position\n");
        return -1;
    }

    int x = -1;

    if(index == 1)
    {
        struct Node *last = head->pre;
        x = head->data;

        if(head->next == head) 
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *temp = head;
            head = head->next;
            last->next = head;
            head->pre = last;

            p = head;
            free(temp);
        }
    }
    else 
    {
        struct Node *p = head;
        for(int i = 0; i < index - 1; i++) 
        {
            p = p->next;
        }

        p->pre->next = p->next;
        p->next->pre = p->pre;
        
        x = p->data;
        free(p);
    }

    return x;
}


void reverse(struct Node *p)
{
    struct Node *temp; 

    do
    {
        temp = p->next;
        p->next = p->pre;
        p->pre = temp;

        p = p->pre;        
    } while (p != head);

    head = p->next;
}

int findMiddle(struct Node *p)
{

    struct Node *q = head;

    do
    {
        p = p->next;
        if (p != head)
        {
            p = p->next;
        }
        q = q->next;

    } while (p != head && p->next != head);

    return q->data;
}



int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(head);

    printf("The middle is: %d\n", findMiddle(head));
    
    // reverse(head);
    // display(head);

    // delete(head, 1);
    // display(head);

    // insert(head, 0, 6);
    // display(head);

    // printf("Length = %d\n", length(first));

    return 0;
}