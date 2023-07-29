#include<iostream>
using namespace std;

int bitChecker(int num){
    int count=0;

    while(num!=0){
        if(num&1){
            count++; //If the right most bit is 1, then the and of that number with 1 will return true
        }
        num=num>>1;
    }
    return count;
}

int main(){
    
    cout<<bitChecker(5);
    return 0;
}