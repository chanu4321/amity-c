#include <stdio.h>
void swap(int *a, int start, int end)
{
    int temp;
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
}
int partition(int *a, int lb, int ub)
{
    int start, end;
    int pivot_item;
    pivot_item = a[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        /* Move start wile item < pivot */
        while (a[start] <= pivot_item)
        {
            start++;
        }
        /* Move end while item > pivot */
        while (a[end] > pivot_item)
        {
            end--;
        }
        if (start < end)
        {
            swap(a, start, end);
            start++;
            end--;
        }
    }
    /* end is final position for the pivot */
    swap(a,lb,end);
    return end;
}
void quicksort(int *a, int lb, int ub)
{
    int pivot;
    if (ub >= lb)
    {
        pivot = partition(a, lb, ub);
        quicksort(a, lb, pivot-1);
        quicksort(a, pivot+1, ub);
    }
}

int main()
{
    int a[5] = {5,6,3,2,7};
    quicksort(a, 0, 4);
    printf("Sorted Array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}