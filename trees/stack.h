#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct stack
{
    int size;
    int top;
    struct Node **s; // Array of pointers to Nodes
};

// Function to initialize a stack
void createStack(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(size * sizeof(struct Node *));
    if (st->s == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to check if the stack is empty
bool isEmptyStack(struct stack *st)
{
    return st->top == -1;
}

// Function to check if the stack is full
bool isFullStack(struct stack *st)
{
    return st->top == st->size - 1;
}

// Function to push an element onto the stack
void push(struct stack *st, struct Node *node)
{
    if (isFullStack(st))
    {
        printf("Stack overflow!\n");
        return;
    }
    st->s[++st->top] = node;
}

// Function to pop an element from the stack
struct Node *pop(struct stack *st)
{
    if (isEmptyStack(st))
    {
        printf("Stack underflow!\n");
        return NULL;
    }
    return st->s[st->top--];
}

// Function to peek at the top element of the stack
struct Node *peek(struct stack *st)
{
    if (isEmptyStack(st))
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    return st->s[st->top];
}

#endif // STACK_H
