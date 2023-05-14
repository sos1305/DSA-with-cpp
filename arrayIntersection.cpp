#include <iostream>

using namespace std;

int main()
{

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 1, 2, 3, 4};
    int arr3[5];
    int s1 = 5;
    int s2 = 5;
    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2)
    {
        if (arr1[i] == arr2[j])
        {
            arr3[k] = arr2[j];
            arr2[j] = INT_MIN;
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << arr3[i] << endl;
    }

    return 0;
}
