#include<iostream>

using namespace std;

bool linearSearch(int arr[],int n, int target){
    if(n==0){
        return false;
    }
    if(arr[0]==target){
        return true;
    }
    else{
        return linearSearch(arr+1,n-1,target);
    }
}

int main(){
    
    int arr[]={1,6,23,5,6,2,43};
    if(linearSearch(arr,sizeof(arr)/sizeof(int),23)){
        cout<<"Element is present";
    }
    else{
        cout<<"Element is not present";
    }

    return 0;
}
