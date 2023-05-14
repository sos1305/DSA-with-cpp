#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{//In each round of bubble sort, we place the ith largest element in its position

    bool swapped = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j+1] < arr[j])
            {
                swap(arr[j+1], arr[j]);
                swapped = true;
            }
        }
        if(swapped == false) 
        {
            break;
        }
    }
}

int main()
{
    int arr[]={5,3,7,9,1};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
