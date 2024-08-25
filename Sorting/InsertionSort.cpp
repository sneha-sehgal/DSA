#include<iostream>
using namespace std;

/*
Insertion Sort
we start by assuming the first element of the array to be sorted
pick up the second element and check where it has to be placed

for (iterate for the key)
    j has index, 1 less than the key
    while (arr[k] > key)
        we move the element to the right
        key in not lost, it is saved in a variable above
    add key to the appropriate place
*/

void InsertionSort(int arr[], int size)
{
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;     

        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;  
    }

    
}

int main()
{
    int arr[] = {12, 10, 8, 2, 76, 43, 34, 5};
    int size = sizeof(arr)/sizeof(int);
    InsertionSort(arr, size);

    for (int x : arr)
        cout << x << " ";

}