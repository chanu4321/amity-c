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
    int ch; char ins;
    struct node *start = NULL;
    struct node *nn,*temp;
    int d,k,pos;
    while (1) {
    printf("Operations on Unsorted Linked List \n \n Press 1 to Insert \n Press 2 to Delete \n Press 3 to Search \n Press 4 to Traverse(Print) \n Press 5 to exit \n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf(" A: Insert at start \n B: Insert at end \n C: Insert at location \n");
        fflush(stdin);
        ins=getchar();
        switch (ins)
        {
        case 'A':
            nn = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &d);
            nn->data = d;
            nn->next = start;
            start = nn;
            printf("element is inserted at the beg : %d \n",nn->data);
            break;
        
        case 'B':
            nn = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &d);
            nn->data = d;
            nn->next = NULL;
            if (start==NULL) {
                start=nn;
            }
            else {
                for(temp=start;temp->next!=NULL;temp=temp->next) {}
            }
            temp->next = nn;
            printf("element is inserted at the end : %d \n",nn->data);
            break;
        
        case 'C':
            scanf("%d", &d);
            scanf("%d",&pos);
            for(temp=start,k=0 ; k<pos ; temp=temp->next) {
                if(temp==NULL) {
                    printf("nodes less than position");
                    break;
                }
                k++;
            }
            nn = (struct node *)malloc(sizeof(struct node));
            nn->data = d;
            nn->next = temp->next;
            temp->next=nn;
            printf("element is inserted at the given location : %d \n",nn->data);
            break;
        }
        }
    
    else if (ch == 2)
    {
        printf(" A: Delete using location \n B: Delete using data value \n ");
    }
    }
    return 0;
}