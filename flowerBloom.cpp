#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*You are given a 2d array flowers, where flowers[i]=[starti,endi], means the ith flower will be in full bloom from
starti to endi(inclusive). You are also given an array people of size n, where people[i] is the time of arrival of the
person to see the flowers.
Return an integer array of size n where answer[i] is the number of flowers that are in full bloom when the ith person
arrives.
*/

vector<int> bloomingFlowers(vector<vector<int>> flowers, vector<int> persons)
{

    // // brute force
    // vector<int> ans;
    // for (int i = 0; i < people.size(); i++)
    // {
    //     int personArrivalTime = people[i];
    //     int flowersBlooming = 0;
    //     for (int j = 0; j < flowers.size(); j++)
    //     {
    //         if (personArrivalTime >= flowers[j][0] && personArrivalTime <= flowers[j][1])
    //         {
    //             flowersBlooming++;
    //         }
    //     }
    //     ans.push_back(flowersBlooming);
    // }
    // return ans;


    // optimized
    vector<int> start, end;
    for (auto &t : flowers)
    {
        start.push_back(t[0]), end.push_back(t[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> res;
    for (int t : persons)
    {
        int started = upper_bound(start.begin(), start.end(), t) - start.begin();
        int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
        res.push_back(started - ended);
    }
    return res;
}

int main()
{
    vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people = {2, 3, 7, 11};
    vector<int> output = bloomingFlowers(flowers, people);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}
