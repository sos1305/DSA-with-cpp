#include <iostream>

using namespace std;

int getPivot(int nums[], int n)
{
    int start = 0;
    int end = n - 1;
    if (nums[start] <= nums[end])
    {
        return end;
    }
    int middle = (start + end) / 2;
    while (start <= end)
    {
        if (nums[middle] > nums[middle + 1])
        {
            return middle;
        }

        if (nums[middle] >= nums[start])
        {
            start = middle + 1;
        }
        else
        {
            end = middle;
        }
        middle = (start + end) / 2;
    }
    return -1;
}

int binarySearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int middle = (start + end) / 2;
    while (start <= end)
    {

        if (arr[middle] == key)
        {
            return middle;
        }

        if (key > arr[middle])
        {
            start = middle + 1;
        }

        else if (key < arr[middle])
        {
            end = middle - 1;
        }

        middle = (start + end) / 2;
    }
    return -1;
}

int findPosition(int arr[], int n, int key)
{
    int pivot = getPivot(arr, n);
    if (arr[pivot] <= key && key <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    int arr[] = {4, 5, 1, 2, 3};
    cout << findPosition(arr, 5, 1);
    return 0;
}
