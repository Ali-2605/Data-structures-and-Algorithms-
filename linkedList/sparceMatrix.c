#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int column; 
    int value;
    struct Node *next;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct Node *first;
};

void create()
{

}

void create(struct sparse *s)
{
    printf("Enter Dimension of sparse natrix\n");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter number of non-zero element\n");
    scanf("%d", &s->num);

    for(int i=0;i<s->num;i++)
    {
        printf("Enter %d non-zero element (row, column, value): ", i+1);
        scanf("%d %d %d", &s->m[]);
    }
    s->first = (struct Node *)malloc(s-> * sizeof (struct element ));
}

void display(struct Node *p)
{

}

int main()
{
    int m, n, num;
    printf("Size of the matrix: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter number of non-zero element\n");
    scanf("%d", &num);
    s->e=(struct element *)malloc(s->num*sizeof(struct element));

    for(int i=0;i<s->num;i++)
    {
        printf("Enter %d non-zero element (row, column, value): ", i+1);
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].k);
    }
}