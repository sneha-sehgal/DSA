#include<iostream>
using namespace std;

/*
Bubble Sort
iterate for the array 
    checking the elements after the original element
        swap

for loop -- to iterate over the array
    for loop -- for iterate over the array
        if element greater than the next one 
            swap
*/

void BubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        for (int x = 0; x < size; x++)
            cout << arr[x] << " ";
        cout << endl;

    }
}

int main()
{
    int arr[] = {3, 1, 9 , 7, 1, 2, 4};
    int size = sizeof(arr)/sizeof(int);
    BubbleSort(arr, size);

    for (int x : arr)
        cout << x << " ";
}