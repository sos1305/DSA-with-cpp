#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
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

int main()
{

    return 0;
}
