#include<iostream>

using namespace std;

int getSum(int arr[],int n){
    //base case
    if(n<=0){
        return 0;
    }
    else{
        //recursive call
        return getSum(arr+1,n-1)+arr[0];
    }
}

int main(){
    int arr[]={2,3,6,3,3,3};
    cout<<"The sum of all elements of array is "<<getSum(arr,6);
    return 0;
}
