#include <iostream>

using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, n - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 5, 6, 8};
    if(isSorted(arr, 5)){
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
    return 0;
}
