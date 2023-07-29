#include<iostream>
#include<queue>
using namespace std;

    int kthSmallest(int arr[], int n, int k) {   
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k) 
            {
                pq.pop(); //in priority queue, elements are sorted in descending order as you enter them
            }
        }
        return pq.top();
    }

int main(){
    int arr[]={4,6,2,1,9,7,3};
    cout<<kthSmallest(arr,sizeof(arr)/sizeof(int), 3);
    return 0;
}
