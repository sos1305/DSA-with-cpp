#include <iostream>

using namespace std;

void sort0_1_2(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        if (arr[left] < arr[right])
        {
            left++;
            right--;
        }
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    int middle = n / 2;
    left = middle - 1;
    while (arr[middle] < arr[left])
    {
        if (arr[left] > arr[middle])
        {
            swap(arr[left], arr[middle]);
            left--;
            middle--;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    cout << "Before swapping" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort0_1_2(arr, 9);
    cout << "After swapping" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
