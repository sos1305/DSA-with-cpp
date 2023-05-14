#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{ // The logic of selection sort is to get the correct value at the ith position as we traverst through the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {6, 3, 7, 2, 9};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
