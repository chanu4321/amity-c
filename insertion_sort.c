#include <stdio.h>
void Insertion_Sort(int *a,int n){
    for(int i=0;i<n;i++){
        int key=a[i];
        int j;
        for(j=i-1;key<a[j] && j>=0;--j){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
}
int main() {
    int a[5]={9, 5, 1, 4, 3};
    Insertion_Sort(a,5);
    printf("Sorted array: ");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}