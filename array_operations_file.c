// traverse, insert, delete, search
#include <stdio.h>
int main() {
    int n;
    printf("enter no. of elements to enter: ");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++){
        printf("enter element to enter: ");
        scanf("%d",&a[i]);
    }
    printf("entered elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
/*
    int item,k;
    printf("enter item to be entered: ");
    scanf("%d",&item);
    printf("enter desired position: ");
    scanf("%d",&k);

    for(int i=n;i>=k;i--){
        a[i+1]=a[i];
    }
    a[k]=item;
    n=n+1;

    printf("entered elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
*/
    int k1;
    
    printf("enter desired position to delete: ");
    scanf("%d",&k1);
    for(int i=k1;i<n-1;i++){
        a[i]=a[i+1];
    }
    n=n-1;
    printf("entered elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

/*
    int item2; 
    printf("enter element to search: ");
    scanf("%d",&item2);
    for(int i=0;i<=n;i++){
        if(a[i]==item2){
            printf("elememt found at %d",i);
        }
    }

/*
    int b,m,e,item3;
    b=0;e=n;m=(b+e)/2;
    for(int i=0; i<=n && a[m]!=item3;i++) {
        if (item3 < a[m]) {
            e=m-1;
        }
        else 
            b=m+1;
    }
    if (a[m]=item3) {
    }
*/
    return 0;
}