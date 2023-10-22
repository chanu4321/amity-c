#include <stdio.h>
void swap(int *a,int j, int small){
    int temp;
    temp=a[j];
    a[j]=a[small];
    a[small]=temp;
}

void Selection_Sort(int *a,int n){
    for(int i=0;i<n-1;i++){
        int small=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[small]){
                small=j;
            }    
        }
        swap(a,i,small);
    }
}
int main() {
    int a[5]={3,1,6,2,5};
    Selection_Sort(a,5);
    printf("Sorted Array: ");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}