#include <iostream>

using namespace std;

void reverse(int arr[], int n)
{

    for (int i = 0; i < n / 2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    reverse(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
