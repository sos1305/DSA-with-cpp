#include<iostream>
#include<cmath>
using namespace std;

bool powerof2(int n){
    for(int i=0;i<=30;i++){
        if(n==pow(2,i)){
            return true;
        }
    }
    return false;
}

int main(){
    cout<<powerof2(1024);
    return 0;
}
