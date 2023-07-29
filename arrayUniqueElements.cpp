#include<iostream>

using namespace std;

//This program is to find the unique element in an array. In the input, there would be n numbers which would be repeated twice and 1 number which is unique.

int findUniqueElement(int arr[], int n){
    int ans=0;
    for(int i=0; i<n; i++){
        ans=ans^arr[i]; //The XOR operation of same numbers is 0
    }
    return ans;
}

int main(){
    int arr[5]={1,2,1,2,3};
    cout<<findUniqueElement(arr,5);
    return 0;
}
