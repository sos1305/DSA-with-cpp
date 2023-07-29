#include<iostream>

using namespace std;

void rotateArray(int arr[],int n, int k){
    if(k%n==0){
        return;
    }
    for(int i=1;i<=k;i++){
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    }
}

int main(){
    int arr[]={1,2,3,4};
    rotateArray(arr,4,4);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
