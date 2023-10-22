// traverse, insert, delete, search
#include <stdio.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
int main()
{
    int n;
    printf("enter no. of elements to enter: ");
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        printf("enter element to enter: ");
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);

    printf("entered elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int item, i;
    printf("enter item to be entered: ");
    scanf("%d", &item);

    for (i = n; a[i] > item; i--)
    {
        a[i + 1] = a[i];
    }
    a[i + 1] = item;
    n = n + 1;
    printf("entered elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    /*
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


        int item2;
        printf("enter element to search: ");
        scanf("%d",&item2);
        for(int i=0;i<=n;i++){
            if(a[i]==item2){
                printf("elememt found at %d",i);
            }
        }
    */

    int b, m, e, item3, index;
    b = 0;
    e = n - 1;
    m = (b + e) / 2;
    printf("enter item to be delete: ");
    scanf("%d", &item3);
    for (int i = 0; i <= n && a[m] != item3; i++)
    {
        if (item3 < a[m])
        {
            e = m - 1;
        }
        else
        {
            b = m + 1;
        }
        m = (int)(b + e) / 2;
    }
    if (a[m] == item3)
    {
        printf("desired element to delete: %d \n", item3);
        for (int i = m; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n = n - 1;
        printf("entered elements: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}