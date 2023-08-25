// push pop menu driven code 
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("enter max no. of stack elements: ");
    scanf("%d",&n);
    int a[n];

    int top = -1;
    while(1) {   
    printf("enter the designated number for desired operation: \n");
    printf(">> to PUSH an element enter 1\n");
    printf(">> to POP an element enter 2\n");
    printf(">> to PEEK at stack enter 3\n");
    printf(">> to exit enter 4\n");
    int stk;
    scanf("%d",&stk);
    switch (stk)
    {
    case 1:
        if (top>=n-1) {
            printf("stack overload\n");
        }
        int push;
        printf("enter element to push: ");
        scanf("%d",&push);
        printf("element pushed!\n");
        a[++top]=push;
        break;
    
    case 2:
        if (top==-1) {
            printf("stack underflow\n");
        }

        printf("element popped: %d\n",a[top]);
        top--;
        break;
    
    case 3:
        printf("cuurent stack elements: \n");
        for(int i=0;i<top;i++){
            printf("%d ",a[i]);
        }
        break;

    case 4:
        exit(0);
    }
    }
    return 0;
}