#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}* front = NULL, *rear = NULL;

void enqueue(int x)
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
        if(front == NULL)
        {
            front = rear = t;
        }
        else 
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node * t;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


void enqueueDE(int x)
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
        if(front == NULL)
        {
            front = rear = t;
        }
        else 
        {
            t->next = front;
            front = t;
        }
    }
}

int dequeueDE()
{
    int x = -1;
    struct Node * t;
    struct Node * p = front;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }

    else
    {
        while(p->next != rear)
        {
            p = p->next;
        }
        
        x = rear->data;
        t = rear;
        rear = p;
        rear->next = NULL;
        free(t);
    }
    return x;
}
int main()
{
     
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueueDE(5);
    enqueueDE(6);
    enqueueDE(7);
    display();

    dequeueDE();
    display();

    return 0;
}