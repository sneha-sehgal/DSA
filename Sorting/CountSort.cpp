#include<iostream>
#include<ctime>
using namespace std;
//O(n)

/*
create a new count_arr with elements equal to the (max element of input array + 1)
fill the count_arr with 0 at all indices
enter the count of each element of the input array to the respective index of count arr
input arr = {3, 1, 9 , 7, 1, 2, 4}
count arr = {0 1 2 3 4 5 6 7 8 9 - index
             0 2 1 1 1 0 0 1 0 1} - count

new output array[size of input array]
iterate thru count_arr
    if value is 0
        pass
    else
        loop till count becomes 0
        add index to output array

*/
class Sorting
{
    private:
    int maxi(int arr[], int n)
    {
        int maximum = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maximum)
                maximum = arr[i];
        }
        return maximum;
    }
    public:
    void CountSort(int input_arr[], int size)
    {
        // size = 7
        // find max to create a new array with max+1 elements
        int max = maxi(input_arr, size);
        
        // initiate count array with value 0 at all indices
        int count_arr[max + 1] = {0};

        //enter the count of every element of input arr
        for (int i = 0; i < size; i++)
        {
            int x = input_arr[i];
            count_arr[x] += 1;
        }
        
        int output_arr[size];
        int j = 0;
        for (int i = 0; i < max+1; i++)//to iterate over the count array
        {
            if (count_arr[i] != 0)
            {
                while (count_arr[i] != 0)
                {
                    output_arr[j] = i;
                    count_arr[i]--;
                    j++;
                    
                }
            }
        }

        for (int i : output_arr)
            cout << i << " ";
        
    }
};

int main()
{
    auto start_time = clock();

    int input_arr[7] = {3, 1, 9 , 7, 1, 2, 4};
    int n = sizeof(input_arr)/sizeof(int);
    Sorting *obj;
    obj -> CountSort(input_arr, n);

    auto end_time = clock();
    cout << "\nthe time taken is : " << end_time - start_time << "ms";
    
}
