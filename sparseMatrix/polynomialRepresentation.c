#include <stdio.h>
#include <stdlib.h>

struct term {
    int coeff;
    int expo;
};

struct polynomial {
    int n;
    struct term *t;
};

void create(struct polynomial *p) {
    printf("Enter number of elements: ");
    scanf("%d", &p->n);
    printf("\n");
    
    p->t = (struct term *)malloc(p->n * sizeof(struct term));
    for (int i = 0; i < p->n; i++) {
        printf("Enter %dth term coeff: ", i + 1);
        scanf("%d", &p->t[i].coeff);

        printf("Enter %dth term expo: ", i);
        scanf("%d", &p->t[i].expo);
        printf("\n");
    }
}

void display(struct polynomial *p) {
    for (int i = 0; i < p->n; i++) {
        printf("%dx^%d", p->t[i].coeff, p->t[i].expo);
        if (i != (p->n) - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct polynomial addition(struct polynomial *p1, struct polynomial *p2) {
    int i = 0, j = 0, k = 0;
    struct polynomial sum;
    sum.t = (struct term *)malloc((p1->n + p2->n) * sizeof(struct term));
    
    while (i < p1->n && j < p2->n) {
        if (p1->t[i].expo > p2->t[j].expo) {
            sum.t[k++] = p1->t[i++];
        }

        else if (p2->t[j].expo > p1->t[i].expo) {
            sum.t[k++] = p2->t[j++];
        }

        else {
            sum.t[k].expo = p1->t[i].expo;
            sum.t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    
    for (; i < p1->n; i++) {
        sum.t[k++] = p1->t[i];
    }
    
    for (; j < p2->n; j++) {
        sum.t[k++] = p2->t[j];
    }
    
    sum.n = k;
    return sum;
}

int main() {
    struct polynomial p1, p2, sum;
    printf("Create the 1st polynomial: \n");
    create(&p1);

    printf("Create the 2nd polynomial: \n");
    create(&p2);

    sum = addition(&p1, &p2);
    display(&p1);
    printf("+\n");
    display(&p2);
    printf("----------------------------------\n");
    display(&sum);

    // Free allocated memory
    free(p1.t);
    free(p2.t);
    free(sum.t);

    return 0;
}
