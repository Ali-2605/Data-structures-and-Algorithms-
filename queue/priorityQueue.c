#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}* front1 = NULL, *rear1 = NULL, * front2 = NULL, *rear2 = NULL, * front3 = NULL, *rear3 = NULL;

void enqueue(int x, int rank)
{
    struct Node *t; 
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Queue is Full\n");
    }

    else
    {
        t->data = x;
        t->next = NULL;
        if(rank == 1)
        {
            if(front1 == NULL)
            {
                front1 = rear1 = t;
            }
            else 
            {
                rear1->next = t;
                rear1 = t;
            }
        }
        if(rank == 2)
        {
            if(front2 == NULL)
            {
                front2 = rear2 = t;
            }
            else 
            {
                rear2->next = t;
                rear2 = t;
            }
        }
        if(rank == 3)
        {
            if(front3 == NULL)
            {
                front3 = rear3 = t;
            }
            else 
            {
                rear3->next = t;
                rear3 = t;
            }
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node * t;

    if(front1 != NULL)
    {
        x = front1->data;
        t = front1;
        front1 = front1->next;
        free(t);
    }
    else if(front1 == NULL)
    {
        x = front2->data;
        t = front2;
        front2 = front2->next;
        free(t);
    }
    else if(front2 == NULL)
    {
        x = front3->data;
        t = front3;
        front3 = front3->next;
        free(t);
    }
    else
    {
        printf("All Queues are Empty\n");
    }
    return x;
}

void display()
{
    struct Node *p1 = front1;
    struct Node *p2 = front2;
    struct Node *p3 = front3;
    printf("Rank 1 Queue: \n");
    while(p1)
    {
        printf("%d ", p1->data);
        p1 = p1->next;
    }
    printf("\n");
    printf("Rank 2 Queue: \n");
    while(p2)
    {
        printf("%d ", p2->data);
        p2 = p2->next;
    }
    printf("\n");
    printf("Rank 3 Queue: \n");
    while(p3)
    {
        printf("%d ", p3->data);
        p3 = p3->next;
    }
    printf("\n");
}

int main()
{
     
    enqueue(1, 1);
    enqueue(2, 1);
    enqueue(3, 2);
    enqueue(4, 2);
    enqueue(5, 3);
    enqueue(6, 3);
    enqueue(7, 3);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();

    return 0;
}