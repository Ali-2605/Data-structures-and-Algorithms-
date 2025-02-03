#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data; 
    struct Node *next;
}* top = NULL;

void push(char x)
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
        t->next = top;
        top = t;
    }
}

char pop()
{
    char x = -1;
    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

char stackTop()
{
    return top->data;
}


int isEmpty()
{
    return top == NULL;
}

int isBalanced(char S[])
{
    for(int i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == '(')
        {
            push('(');
        }
        else if(S[i] == ')')
        {
            if(isEmpty())
            {
                return 0;
            }
            pop();
        }
    }
    if(isEmpty())
    {
        return 1;
    }
    return 0;
}


int isBalanced2(char S[])
{
    for(int i = 0; S[i] != '\0'; i++)
    {
        if(S[i] == '(' || S[i] == '[' || S[i] == '{')
        {
            push(S[i]);
        }
        else if(S[i] == ')' || S[i] == ']' || S[i] == '}')
        {
            if(isEmpty())
            {
                return 0;
            }
            int x = pop();
            if(!(x == S[i] - 1 || x == S[i] - 2))
            {
                return 0;
            }
        }
    }
    if(isEmpty())
    {
        return 1;
    }
    return 0;
}

int isOperand(char x)
{
    if(x == '+' || x == '*' || x == '-' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pre(char x)
{
    if(x == '+' || x == '-')
    {
        return 1;
    }
    else if(x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}



char * inToPost(char *infix)
{
    push('#');
    char * postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(pre(infix[i]) > pre(stackTop()))
            {
                push(infix[i++]);
            }
            else 
            {
                postfix[j++] = pop();
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j - 1] = '\0';
    return postfix;
}

int isOperand2(char s)
{
    if(s=='*' || s=='/' || s=='+' || s=='-' || s=='^' || s=='(' || s==')')
        return 0;
    else 
        return 1;
}

int outPre(char s)
{
    if(s=='+' || s=='-')
    {
        return 1;
    }
    else if(s=='*' || s=='/')
    {
        return 3;
    }
    else if(s=='^')
    {
        return 6;
    }
    else if(s=='(')
    {
        return 7;
    }
    else if(s==')')
    {
        return 0;
    }
    return 0;
}

int inPre(char s)
{
    if(s=='+' || s=='-')
    {
        return 2;
    }
    else if(s=='*' || s=='/')
    {
        return 4;
    }
    else if(s=='^')
    {
        return 5;
    }
    else if(s=='(')
    {
        return 0;
    }
    return -1;
}

char* inToPost2(char *infix)
{
    push('#');
    char * postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i=0,j=0;

    while(infix[i] != '\0')
    {
        if(isOperand2(infix[i]))
        {
           postfix[j++] = infix[i++];
        }
        else
        {
            if(outPre(infix[i]) > inPre(stackTop()))
            {
                push(infix[i++]);
            }
            else if(outPre(infix[i]) < inPre(stackTop()))
            {
                   postfix[j++] = pop();
            }
            else
            {
                pop();
                i++;
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j - 1]='\0';
    return postfix;
}

int eval(char *postFix)
{
    int x1, x2;
    for(int i = 0; postFix[i] != '\0'; i++)
    {
        if(isOperand(postFix[i]))
        {
            push(postFix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postFix[i])
            {
                case '+':
                    push(x1 + x2);
                    break;
                case '-':
                    push(x1 - x2);
                    break;
                case '*':
                    push(x1 * x2);
                    break;
                case '/':
                    push(x1 / x2);
                    break;
                default:
                    break;
            }
        }
    }
    return pop();
}

int main()
{
    char infix[] = "3*5+6/2-4";
    printf("Infix: %s\nPostfix: %s\n", infix, inToPost(infix));
    printf("Result: %d\n", eval(inToPost(infix)));
    return 0;
}