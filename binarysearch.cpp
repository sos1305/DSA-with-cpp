#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    int middle = (start + end) / 2;
    while (start <= end)
    {

        if (arr[middle] == key)
        {
            return middle;
        }

        if (key > arr[middle])
        {
            return binarySearch(arr,middle+1,end,key);
        }

        else if (key < arr[middle])
        {
            return binarySearch(arr,start,middle - 1,key);
        }

        middle = (start + end) / 2;
    }
    return -1;
}

int main()
{
    int arr[]={1,2,5,6,8,9};
    cout<<binarySearch(arr,0,5,11);
    return 0;
}
