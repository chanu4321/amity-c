#include <stdio.h>
int main() {
    int n;
    printf("enter no. of elements to enter: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter element to enter: ");
        scanf("%d",&a[i]);
    }
    printf("entered elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int k1,item2; 
    printf("enter element to delete: ");
    scanf("%d",&item2);
    for(int i=0;i<=n;i++){
        if(a[i]==item2){
            printf("elememt found at index value %d\n",i);
            k1=i;
        }
    }

    printf("element getting deleted: %d\n",a[k1]);
    for(int i=k1;i<n-1;i++){
        a[i]=a[i+1];
    }
    n=n-1;
    printf("entered elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}