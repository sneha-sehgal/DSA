#include<iostream>
#include<ctime>
using namespace std;

//O(N^2)

void SelectionSort(int arr[], int n)
{
    // condition 1 - traverse array , find the min value, swap with the first element
    // condition 2 - traverse REST array, find min, swap with second element
    // condition 3 - repeat till the max value automatically gets placed at the end

    /*
    Approach
    one loop - to arrange the set the start of the array - i iterator
        one loop - find the min elements - whose start gets incremented by 1
            swap the min to the i th element
            -- first 0, then 1, 2, 3, 4, .....

    */
    int min = arr[0];
    int index, temp;
    for (int i = 0; i < n; i++)
    {
        min = arr[i]; 
        for (int j = i; j < n; j++)//loop that returns min
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        } 
        if (arr[i] != min)
        {
            temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
        }
        
    }
}
int main()
{
    auto start_time = clock();

    int arr[] = {2, 5, 3, 4, 9, 8, 10, 11, 54, 23, 67, 45};
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
            
    auto end_time = clock();
    cout << "\nthe time taken is " << end_time-start_time<< "ms" << endl;

    return 0;
}