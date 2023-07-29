#include <iostream>

using namespace std;

void pairSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " " << arr[j];
                cout << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    pairSum(arr, 5, 5);
    return 0;
}
