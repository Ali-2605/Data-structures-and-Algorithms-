#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data; 
    struct Node *next;
};

void push(struct Node *s, char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = s;
        s = t;
    }
}

char pop(struct Node *s)
{
    char x = -1;
    if(s == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *t;
        t = s;
        s = s->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display(struct Node *s1, struct Node *s2)
{
    while(s2 != NULL)
    {
        printf("%d ", pop(s2));
    }
    while(s1 != NULL)
    {
        push(&s2, pop(s1));
    }
    while(s2 != NULL)
    {
        printf("%d ", pop(s2));
    }
    printf("\n");
}

void enqueue(struct Node *s1, int x)
{
    push(s1, x);
}

int isEmpty(struct Node *s)
{
    return s == NULL;
}

int dequeue(struct Node *s1, struct Node *s2)
{
    int x = -1;
    if(isEmpty(s2))
    {
        if(isEmpty(s1))
        {
            printf("Queue is Empty\n");
        }
        else
        {
            while(!isEmpty(s1))
            {
                push(s2, pop(s1));
            }
        }
    }
    return pop(s2);
}
int main()
{
    
}