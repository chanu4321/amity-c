#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the max no. of queue elements: ");
    scanf("%d",&n);
    int cq[n];
    int item;
    int f=-1,r=-1;
    while (1) {
        printf("enter the designated number for desired operation: \n");
        printf(">> to ENQUEUE an element enter 1\n");
        printf(">> to DEQUEUE an element enter 2\n");
        printf(">> to exit enter 3\n");
        int stk;
        scanf("%d",&stk);
        switch (stk) {
            case 1:
                if((f==0 && r>=n-1) || f==r+1){
                    printf("queue overflow \n");
                }
                else {
                    printf("enter element to be inserted: ");
                    scanf("%d",&item);
                    if(f==-1 && r==-1) {
                        f=r=0;
                    }
                    else if(r==n-1 && f>=0) {
                        r=0;
                    }
                    else {
                        r++;
                    }
                    cq[r]=item;
                }
                break;

            case 2:
                if(f==-1){
                    printf("queue underflow");
                }
                else {
                    printf("%d \n",cq[f]);
                    if(f==r){
                        f=r=-1;
                    }
                    else if(f==n-1 && r>=0) {
                        f=0;
                    }
                    else {
                        f++;
                    }
                }
                break;

            case 3:
                exit(0);
            default:
                printf("\nWrong input, please enter from given choices.");
        }
    }
    return 0;
}