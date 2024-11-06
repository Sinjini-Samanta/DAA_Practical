//Write a program using recursion to implement QuickSort

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    
    while(i<j){
        while(arr[i]<=pivot && i<= h-1){
            i++;
        }
        while (arr[j]>pivot && j>=l+1){
            j--;
        }
        if(i<j){
            swap(&arr[i], & arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}
void quickSort(int arr[], int l, int h){
    if(l<h){
        int p = partition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}
void PrintArray(int arr[], int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main() {
    //int n,i;
    int arr[] = {6, 2, 10, 5, 4, 11, 15, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("\nThe sorted array is: ");
    PrintArray(arr,n);

    return 0;
}
