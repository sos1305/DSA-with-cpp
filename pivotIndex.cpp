#include <iostream>
// This program is to find the pivot index in a sorted rotated array, i.e., the index of the minimum element
// We are going to use binary search for the following purpose
using namespace std;

int getPivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int middle = (start + end) / 2;
    while (start < end)
    {
        if (arr[middle] >= arr[0])
        {
            start = middle + 1;
        }
        else
        {
            end = middle;
        }
        middle = (start + end) / 2;
    }
    return start;
}

int main()
{

    int arr[5] = {4, 5, 1, 2, 3};
    cout << "The pivot is at index " << getPivot(arr, 5);
    return 0;
}
