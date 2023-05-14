#include <iostream>

using namespace std;

void sort0and1(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        if (arr[left] == 0)
        {
            left++;
        }
        if (arr[right] == 1)
        {
            right--;
        }

        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    int arr[] = {1, 1, 0, 0, 0, 0, 1, 0};
    cout << "Before swapping" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort0and1(arr, 8);
    cout << "After swapping" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
