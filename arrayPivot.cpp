#include <iostream>

//bad program
using namespace std;

int pivotIndex(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int pivot = (start + end) / 2;

    while (pivot>=start && pivot<=end)
    {
        int leftsum = 0;
        int rightsum = 0;
        for (int i = start; i < pivot; i++)
        {
            leftsum = leftsum + arr[i];
        }
        for (int i = pivot + 1; i <= end; i++)
        {
            rightsum = rightsum + arr[i];
        }
       
        if (leftsum == rightsum)
        {
            return pivot;
        }
        else if (leftsum < rightsum)
        {
            if(pivot==start){
                break;
            }
            pivot = pivot + 1;
        }
        else
        {
            if(pivot==end){
                break;
            }
            pivot = pivot - 1;
        }
    }
    return -1;
}

int main()
{
    int nums[] = {1,2,3};
    cout<<"The pivot index is "<<pivotIndex(nums,3);
    return 0;
}
