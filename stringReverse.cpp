#include<iostream>

using namespace std;

void reverse(string &s,int start=0){
    if(start>(s.length()-1-start)){
        return;
    }
    else{
        swap(s[start],s[s.length()-1-start]);
        reverse(s,start+1);
    }
}

int main(){
    string s="soumya";
    cout<<"String before reversing:"<<s<<endl;
    reverse(s);
    cout<<"String after reversing:"<<s<<endl;    
    return 0;
}
