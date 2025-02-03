#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top; 
    int *s; 
};

void create(struct stack *st)
{
    printf("Enter the size of the Stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct stack *st)
{
    if(st->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for(int i = st->top; i >= 0; i--)
    {
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

int isEmpty(struct stack *st)
{
    return st->top == 1;
}

int isFull(struct stack *st)
{
    return st->top == st->size - 1;
}

void push(struct stack *st, int num)
{
    if(st->top == st->size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = num;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack *st, int pos)
{
    int x = -1;
    if(st->top - pos + 1 < 0)
    {
        printf("Invalid position");
    }
    else
    {
        int index = st->top - pos + 1;
        x = st->s[index];
    }   
    return x;
}

int stackTop(struct stack *st)
{
    if(st->top == 1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return st->s[st->top];
    }
}



int main()
{
    struct stack st;
    create(&st);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    printf("Peek at index 3: %d\n", peek(&st, 5));
    printf("the value at the stack top is: %d\n", stackTop(&st));
    stackTop(&st);
    display(&st);

    printf("Poped the value: %d\n", pop(&st));
    printf("Poped the value: %d\n", pop(&st));
    printf("Poped the value: %d\n", pop(&st));
    display(&st);

    push(&st, 5);
    display(&st);


}