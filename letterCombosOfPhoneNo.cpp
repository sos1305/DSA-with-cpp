#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string digits, vector<string> &ans, string output, string mapping[], int index)
{
    // base case
    if (digits.length() == 0)
    {
        return;
    }
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, ans, output, mapping, index + 1); // recursive call
        output.pop_back();                              // backtracking
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    string output = "";
    solve(digits, ans, output, mapping, index);
    return ans;
}
int main()
{
    string digits= "132";
    vector<string>combinations=letterCombinations(digits);
    cout<<"All possible combinations for the digits "<<digits<<" are ";
    for(auto i:combinations){
        cout<<i<<" ";
    }
    return 0;
}
