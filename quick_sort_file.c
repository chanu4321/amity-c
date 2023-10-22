#include <stdio.h>
void swap(int *a, int left, int right)
{
    int temp;
    temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}
int partition(int *a, int low, int high)
{
    int left, right;
    int pivot_item;
    pivot_item = a[low];
    left = low;
    right = high;
    while (left < right)
    {
        /* Move left wile item < pivot */
        while (a[left] <= pivot_item)
        {
            left++;
        }
        /* Move right while item > pivot */
        while (a[right] > pivot_item)
        {
            right--;
        }
        if (left < right)
        {
            swap(a, left, right);
            left++;
            right--;
        }
    }
    /* right is final position for the pivot */
    a[low] = a[right];
    a[right] = pivot_item;
    return right;
}
void quicksort(int *a, int low, int high)
{
    int pivot;
    if (high >= low)
    {
        pivot = partition(a, low, high);
        quicksort(a, low, pivot-1);
        quicksort(a, pivot+1, high);
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