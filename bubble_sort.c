#include <stdio.h>
void swap(int* arr, int i, int j) 
{ 
    int temp = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1); } } } }
int main()
{
    int arr[5] = { 5, 1, 4, 2, 8 };
    bubbleSort(arr,5);
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) 
        printf("%d ", arr[i]);
    return 0;
}