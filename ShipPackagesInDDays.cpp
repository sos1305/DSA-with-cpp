/*A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

#include <iostream>

using namespace std;

bool isPossible(int weights[], int size, int days, int middle)
{
    int weightCount = 0;
    int dayCount = 1;
    for (int i = 0; i < size; i++)
    {
        if (weightCount + weights[i] > middle)
        {
            dayCount++;
            weightCount = 0;
        }
        if (dayCount > days || weights[i] > middle)
        {
            return false;
        }
        weightCount = weightCount + weights[i];
    }
    return true;
}

int shipWithinDays(int weights[], int size, int days)
{

    int start = 0;
    int end = 0;
    for (int i = 0; i < size; i++)
    {
        end += weights[i];
    }
    int middle = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (isPossible(weights, size, days, middle))
        {
            ans = middle;
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
        middle = (start + end) / 2;
    }
    return ans;
}

int main()
{
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<shipWithinDays(weights, 10, 5);
    return 0;
}
