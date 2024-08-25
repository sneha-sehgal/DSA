#include<iostream>
using namespace std;

/*
Quick Sort
Partition - elements to the right are greater
          - elements to the left are smaller
fix a pivot, lets assume the first element is the pivot
    pointer that starts from the element after pivot -- find element greater than pivot
    pointer that starts from the end -- finds smaller element than pivot

    while loop -- to swap the positions until the correct position of the partition is found
    if there is no element smaller than the pivot
        pivot is in the correct position
    else if no element greator then the pivot
        swap with position of end pointer -- automatically place it at the end
    else if end_pointer < start_pointer
        swap pivot with the end pointer
*/

int Paritition(int arr[], int start, int end)
{
    int pivot = start;
    int start_pointer = start + 1;
    int end_pointer = end;
    int temp;

    while (start_pointer < end_pointer)
    {
        while (arr[start_pointer] <= arr[pivot])
        {
            start_pointer++;
        }
        while (arr[end_pointer] > arr[pivot])
        {
            end_pointer--;
        }

        if (end_pointer > start_pointer) // there is no element smaller than the pivot
        {
            // swap start pointer and end pointer
            temp = arr[start_pointer];
            arr[start_pointer] = arr[end_pointer];
            arr[end_pointer] = temp;      
        }
        for (int x = 0; x < 7; x++)
            cout << arr[x] << " ";
        cout << endl;
    }
    
    temp = arr[start];
    arr[start] = arr[end_pointer];
    arr[end_pointer] = temp;

    
    return end_pointer;
}

void QuickSort(int arr[],int start, int end)
{
    int PartIndex;
    if (start < end)
    {
        PartIndex = Paritition(arr, start, end);
        QuickSort(arr, start, PartIndex - 1);
        QuickSort(arr, PartIndex + 1, end);
    }
}

int main()
{
    int arr[] = {9, 4, 4, 8, 7, 5, 6};
    int size = sizeof(arr)/sizeof(int);
    QuickSort(arr, 0, size-1);

    for (int x = 0; x < size; x++)
        cout << arr[x] << " ";
    return 0;
}