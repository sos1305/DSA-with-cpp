#include<iostream>

using namespace std;

int partition(int arr[], int s, int e){
    int ele=arr[s];
    int pos=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<ele){
            pos++;
        }
    }
    swap(arr[s],arr[s+pos]);
    int index=s+pos;

    int left=s;
    int right=e;
    while(left<index && right>index){
        while(arr[left]<=ele){
            left++;
        }
        while(arr[right]>ele){
            right--;
        }
        if(left<index && right>index){
            swap(arr[left++],arr[right--]);
        }
    }

    return index;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    else{
        int p=partition(arr, s, e);
        quickSort(arr,s,p-1);
        quickSort(arr,p+1,e);
    }
}

int main(){

    int arr[]={1,7,2,5,4};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
}
