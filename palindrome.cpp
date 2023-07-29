#include<iostream>

using namespace std;

bool isPalindrome(string s, int i=0){
    if(i>s.length()-i-1){
        return true;
    }
    if(s[i]!=s[s.length()-i-1]){
        return false;
    }
    else{
        return isPalindrome(s,i+1);
    }
}

int main(){
    
    string s="sos";
    if(isPalindrome(s)){
        cout<<"String is palindrome";
    }
    else{
        cout<<"String is not palindrome";
    }
    return 0;
}
