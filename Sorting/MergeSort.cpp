#include <iostream>
using namespace std;

void Merge(int array[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int SortedArray[100];
    while (i <= mid && j <= end)
    {
        if(array[i] < array[j])
        {
            SortedArray[k] = array[i];
            i++;
            k++;
        }
        else{
            SortedArray[k] = array[j];
            j++;
            k++;
        }
    }
    //while loop to add remaining elements of sub array from start to mid
    while (i <= mid)
    {
        SortedArray[k] = array[i];
        k++;
        i++;
    }
    //while loop to add remaining elements of sub array from mid to end
    while (j <= end)
    {
        SortedArray[k] = array[j];
        k++;
        j++;
    }
    // copy Sorted array to normal array
    for (int i = start; i <= end; i++)
    {
        array[i] = SortedArray[i];
    }
}

void MergeSort(int array[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end)/2;
        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, start, mid, end);
    }
}

int main()
{
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int end = sizeof(arr)/sizeof(int) - 1;
    MergeSort(arr, 0, end);

    for (int i = 0 ; i < 7; i++)
        cout << arr[i] << " ";

    return 0;
}