#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>nums, vector<vector<int>>&ans, vector<int>output, int index)
{
    //base case
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }

    //recursive case
    //exclude
    solve(nums, ans, output, index+1);

    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums, ans, output, index+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int>output;
        int index=0;
        solve(nums, ans, output, index);
        return ans;
    }

int main(){
    vector<int>set={1,2,3};
    vector<vector<int>>powerSet=subsets(set);
    cout<<"All possible subsets of the given set are:"<<endl;
    for(int i=0;i<powerSet.size();i++){
        for(int j=0;j<powerSet[i].size();j++){
            cout<<powerSet[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
