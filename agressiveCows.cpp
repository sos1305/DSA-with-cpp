#include <iostream>
#include <vector>
// This program is to place k agressive cows in the stalls such that the distance between them is maximum, the element of the array shows the stall number
using namespace std;

bool isPossible(vector<int> stalls, int k, int middle)
{
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= middle)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int middle = (start + end) / 2;
    while (start <= end)
    {
        if (isPossible(stalls, k, middle))
        {
            ans = middle;
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
    return ans;
}
int main()
{
    
    return 0;
}
