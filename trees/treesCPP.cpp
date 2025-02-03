#include <iostream>
#include "queueCPP.h"
using namespace std;


class Tree 
{
private:
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }
    void createTree();
    void preOrder(){preOrder(root);}
    void preOrder(Node *p);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
    void postOrder(){postOrder(root);}
    void postOrder(Node *p);
    void levelOrder(){levelOrder(root);}
    void levelOrder(Node *p);
    int height(){return height(root);}
    int height(Node *p);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter the left Child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            q.enqueue(t);
        }
        printf("Enter the right Child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->rightChild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->leftChild);
        preOrder(p->rightChild);
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->leftChild);
        printf("%d ", p->data);
        inOrder(p->rightChild);
    }
}

void Tree::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->leftChild);
        postOrder(p->rightChild);
        printf("%d ", p->data);
    }
}

int Tree::height(Node *root)
{
    int x = 0, y = 0;
    if(root == 0)
    {
        return 0;
    }
    x = height(root->leftChild);
    y = height(root->rightChild);
    if(x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

void Tree::levelOrder(Node *p)
{
    Queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->leftChild)
        {
            printf("%d ", root->leftChild->data);
            q.enqueue(root->leftChild);
        }
        if(root->rightChild)
        {
            printf("%d ", root->rightChild->data);
            q.enqueue(root->rightChild);
        }
    }    
}

int main()
{
    Tree t;

    t.createTree();
    printf("Pre order: \n");
    t.preOrder();
    printf("\n");

    printf("In order: \n");
    t.inOrder(); 
    printf("\n");

    printf("Post order: \n");
    t.postOrder();
    printf("\n");

    return 0;
}
