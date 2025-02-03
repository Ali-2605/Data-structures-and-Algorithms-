#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        Node *t = new Node; 
        if(t == NULL)
        {
            printf("Stack is full\n");
        }
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop()
    {
        int x = -1;
        if (top == NULL)
        {
            printf("Stack is empty\n");
        }
        else
        {
            Node *t = top;
            top = top->next;
            x = t->data;
            delete t;
        }
        return x;
    }

    void display()
    {
        Node *p = top;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
};

int main()
{
    Stack stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.display();

    stk.pop();
    stk.display();
    return 0;
}