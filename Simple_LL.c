#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int ch;
    char ins, del;
    struct node *start = NULL;
    struct node *nn, *temp, *save;
    int d, k, pos;
    while (1)
    {
        printf("Operations on Unsorted Linked List \n \n Press 1 to Insert \n Press 2 to Delete \n Press 3 to Search \n Press 4 to Traverse(Print) \n Press 5 to exit \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(" A: Insert at start \n B: Insert at end \n C: Insert at location \n");
            fflush(stdin);
            ins = getchar();
            switch (ins)
            {
            case 'A':
                nn = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &d);
                nn->data = d;
                nn->next = start;
                start = nn;
                printf("element is inserted at the beg : %d \n", nn->data);
                break;

            case 'B':
                nn = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &d);
                nn->data = d;
                nn->next = NULL;
                if (start == NULL)
                {
                    start = nn;
                }
                else
                {
                    for (temp = start; temp->next != NULL; temp = temp->next)
                    {
                    }
                }
                temp->next = nn;
                printf("element is inserted at the end : %d \n", nn->data);
                break;

            case 'C':
                scanf("%d", &d);
                scanf("%d", &pos);
                for (temp = start, k = 0; k < pos; temp = temp->next)
                {
                    if (temp == NULL)
                    {
                        printf("nodes less than position");
                        break;
                    }
                    k++;
                }
                nn = (struct node *)malloc(sizeof(struct node));
                nn->data = d;
                nn->next = temp->next;
                temp->next = nn;
                printf("element is inserted at the given location : %d \n", nn->data);
                break;
            }
            break;

        case 2:
            printf(" A: Delete using location \n B: Delete using data value \n ");
            fflush(stdin);
            del = getchar();
            switch (del)
            {
            case 'A':
                if (start == NULL)
                {
                    printf("list is empty");
                    break;
                }
                scanf("%d", &pos);
                while (pos == 0)
                {
                    temp = start;
                    start = start->next;
                    free(temp);
                    break;
                }
                save = start;
                temp = start->next;
                while (temp != NULL && pos > 0)
                {
                    for (int i = 0; i < pos; i++)
                    {
                        save = save->next;
                        temp = temp->next;
                    }
                    save->next = temp->next;
                    free(temp);
                    break;
                }
                if (temp == NULL)
                {
                    printf("data not in list");
                }
                break;

            case 'B':
                if (start == NULL)
                {
                    printf("list is empty");
                    break;
                }
                scanf("%d", &d);
                if (start->data == d)
                {
                    temp = start;
                    start = start->next;
                    free(temp);
                    break;
                }
                save = start;
                temp = start->next;
                while (temp != NULL)
                {
                    if (temp->data == d)
                    {
                        save->next = temp->next;
                        free(temp);
                        printf("Node deleted");
                        break;
                    }
                    else
                    {
                        save = temp;
                        temp = temp->next;
                    }
                }
                if (temp == NULL)
                {
                    printf("data not in list");
                }
                break;
            }
            break;
        case 3:
            
            break;
        case 4:
            if (start == NULL)
            {
                printf("list is empty");
                break;
            }
            for (temp = start; temp != NULL; temp = temp->next)
            {
                printf("%d\n", temp->data);
            }
            break;
        }
    }
    return 0;
}