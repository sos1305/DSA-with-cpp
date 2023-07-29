#include<iostream>

using namespace std;

//Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

long long maxSubarraySum(int arr[], int n){
        long long int maxsoFar=-2345322;
        long long int maxEndingHere=0;
            
        for(int i=0;i<n;i++){
            maxEndingHere+=arr[i];
            if(maxsoFar<maxEndingHere){
                maxsoFar=maxEndingHere;
                
            }
            if(maxEndingHere<0){
                maxEndingHere=0;
                
            }
        }
        return maxsoFar;
}

int main(){
    int arr[]={-1,3,2,6,8,-3};
    cout<<maxSubarraySum(arr,6);
    return 0;
}
