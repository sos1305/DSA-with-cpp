#include<iostream>

using namespace std;

char tolower(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        ch=ch-'A'+'a';
        return ch;
    }
}

bool isPalindrome(char arr[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(tolower(arr[s])!=tolower(arr[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int main(){
    cout<<tolower('H');
    cout<<isPalindrome("NooN",4);
    return 0;
}
