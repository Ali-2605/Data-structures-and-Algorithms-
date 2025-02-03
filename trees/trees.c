#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter the left Child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            enqueue(&q, t);
        }
        printf("Enter the right Child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->rightChild = t->leftChild = NULL;
            p->rightChild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preOrder(p->leftChild);
        preOrder(p->rightChild);
    }
}

void inOrder(struct Node *p)
{
    if(p)
    {
        preOrder(p->leftChild);
        printf("%d ", p->data);
        preOrder(p->rightChild);
    }
}


void postOrder(struct Node *p)
{
    if(p)
    {
        preOrder(p->leftChild);
        preOrder(p->rightChild);
        printf("%d ", p->data);
    }
}

void IpreOrder(struct Node *p)
{
    struct stack stk;
    createStack(&stk, 100);
    while(p || !isEmptyStack(&stk))
    {
        if(p) 
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->leftChild;  
        }
        else 
        {
            p = pop(&stk);
            p = p->rightChild;
        }

    }
}

void IinOrder(struct Node *p)
{
    struct stack stk;
    createStack(&stk, 100);
    while(p || !isEmptyStack(&stk))
    {
        if(p) 
        {
            push(&stk, p);
            p = p->leftChild;  
        }
        else 
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rightChild;
        }

    }
}

void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if(p->leftChild)
        {
            printf("%d ", p->leftChild->data);
            enqueue(&q, p->leftChild);
        }
        if(p->rightChild)
        {
            printf("%d ", p->rightChild->data);
            enqueue(&q, p->rightChild); 
        }
    }
}

int main()
{
    createTree();
    printf("Pre order\n");
    preOrder(root);
    printf("\n");
    printf("Pre order Treversal\n");
    IpreOrder(root);
    printf("\n");

    printf("in order \n");
    inOrder(root);
    printf("\n");
    printf("In order Treversal\n");
    IinOrder(root);
    printf("\n");


    printf("Post order \n");
    postOrder(root);
    printf("\n");

    printf("Level Order: \n");
    levelOrder(root);
    printf("\n");

}