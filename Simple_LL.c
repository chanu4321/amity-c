#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};

void LL_insert()
{
}

int main()
{
    int ch; char ins;
    struct node *start = NULL;
    struct node *nn;
    int d;
    printf("Operations on Unsorted Linked List \n \n Press 1 to Insert \n Press 2 to Delete \n Press 3 to Search \n Press 4 to Traverse(Print) \n Press 5 to exit \n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf(" A: Insert at start \n B: Insert at end \n C: Insert at location \n");
        fflush(stdin);
        ins=getchar();
        printf("%c",ins);
        switch (ins)
        {
        case 'A':
            nn = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &d);
            nn->data = d;
            nn->next = start;
            start = nn;

            printf("element is insetred at the beg : %d",nn->data);
        }
    }
    else if (ch == 2)
    {
        printf(" A: Delete at start \n B: Delete at end \n C: Delete at location \n");
    }

    return 0;
}