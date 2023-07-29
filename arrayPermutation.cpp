#include <iostream>
#include <vector>
using namespace std;
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[j]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> permutations=permute(arr);
    cout<<"All the permutations of the vector are "<<endl;
    for(int i=0;i<permutations.size();i++){
        cout<<endl;
        for(int j=0;j<arr.size();j++){
            cout<<permutations[i][j]<<" ";
        }
    }
    return 0;
}
