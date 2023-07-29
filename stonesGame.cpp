#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0. */

int lastStoneWeight(vector<int> &stones)
{
    sort(stones.begin(), stones.end(), greater<int>());
    while (stones.size() > 0 && stones.size() > 1)
    {

        int result = stones[0] - stones[1];
        if (result != 0)
        {
            stones.erase(stones.begin());
            stones[0] = result;
            sort(stones.begin(), stones.end(), greater<int>());
        }
        else
        {
            stones.erase(stones.begin(), stones.begin() + 2);
        }
    }
    if (stones.size())
    {
        return stones[0];
    }
    return 0;
}

int main()
{
    vector<int> stones = {1, 5, 2, 6, 3, 4, 7, 9};
    cout << "The weight of the last remaining stone is " << lastStoneWeight(stones) << endl;
    return 0;
}
