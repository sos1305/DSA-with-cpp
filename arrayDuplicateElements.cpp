#include<iostream>

using namespace std;

//This program is to find the duplicate element in an array. In the input, there would be n numbers which would be there in the array once and 1 number which is repeated twice. Also, all the numbers in the array lie within the range 1 to n-1.

int findDuplicateElement(int arr[], int n){
    int ans=0;
    for(int i=0; i<n; i++){
        ans=ans^arr[i];
    }
    for(int i=1; i<n ; i++){
        ans=ans^i;
    }
    return ans;
}

int main(){
    int arr[5]={1,2,3,4,3};
    cout<<findDuplicateElement(arr,5);
    return 0;
}
