#include <iostream>

using namespace std;

int firstOcc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int middle = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {

        if (arr[middle] == key)
        {
            ans = middle;
            end = middle - 1;
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
    return ans;
}

int lastOcc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int middle = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {

        if (arr[middle] == key)
        {
            ans = middle;
            start = middle + 1;
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
    return ans;
}

// If we have to find the total number of occurences, then it is lastocc - 1stocc + 1
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 5};
    cout << "The 1st and last occurence of 3 is at " << firstOcc(arr, 10, 3) << " and " << lastOcc(arr, 10, 3) << endl;
    cout << "The total number of occurences of 3 is " << lastOcc(arr, 10, 3) - firstOcc(arr, 10, 3) + 1;
    return 0;
}
