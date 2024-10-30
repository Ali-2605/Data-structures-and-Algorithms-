#include<stdio.h>
#include<stdlib.h>


struct element{
    int i;
    int j;
    int k;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s)
{
    printf("Enter Dimension of sparse natrix\n");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter number of non-zero element\n");
    scanf("%d", &s->num);
    s->e=(struct element *)malloc(s->num*sizeof(struct element));

    for(int i=0;i<s->num;i++)
    {
        printf("Enter %d non-zero element (row, column, value): ", i+1);
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].k);
    }
}
void display(struct sparse * s)
{
    int k=0;
    for(int i=0;i<s->m;i++)
    {
        for(int j=0;j<s->n;j++)
        {
            if (i == s->e[k].i && j == s->e[k].j)
            {
                printf("%d ", s->e[k++].k);
            }

            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse * add(struct sparse * s1, struct sparse * s2)
{
    if(s1->m!=s2->m || s1->n!=s2->n)
        return 0;
    
    struct sparse *sum;
    int i = 0, j = 0, k = 0;
    
    sum = (struct sparse * ) malloc(sizeof(struct sparse));
    sum->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));
    sum->m=s1->m;
    sum->n=s1->n;

    while (i < s1->num && j < s2->num)
    {
        // row of s1 is less than s2
        if (s1->e[i].i < s2->e[j].i) 
        {
            printf("row of s1 is less than s2\n");
            sum->e[k++] = s1->e[i++];
        }

        // row of s1 is more than s2
        else if (s1->e[i].i > s2->e[j].i) 
        {
            printf("row of s1 is more than s2\n");
            sum->e[k++] = s2->e[j++];
        }
        
        else
        {
            // column of s1 is less than s2
            if (s1->e[i].j < s2->e[j].j)
            {
                printf("column of s1 is less than s2\n");
                sum->e[k++] = s1->e[i++];
            }

            // column of s1 is more than s1
            else if (s1->e[i].j > s2->e[j].j)
            {
                printf("column of s1 is more than s2\n");
                sum->e[k++] = s2->e[j++];
            }

            // row and column both are same
            else 
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].k = sum->e[k].k + s2->e[j++].k;
                printf("row and column both are same\n");
            }
        }
    }


    //remaining elements 
    for(;i < s1->num; i++)
    {
        printf("I am here ");
        sum->e[k++] = s1->e[i];
    }

    for(;j < s2->num; j++)
    {        
        printf("I am there ");
        sum->e[k++] = s2->e[j];
    }

    sum->num = k;

    return sum;
}

int main()
{
    struct sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);
    
    printf("First Matrix: \n");
    display(&s1);

    printf("Second Matrix: \n");
    display(&s2);

    printf("First Matrix + Second Matrix is: \n");
    display(s3);

    return 0;
}