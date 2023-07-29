#include<iostream>

using namespace std;

char maxOccuringCharacter(string s){
    int arr[26]={0};
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        int var=ch-'a';
        arr[var]++;
    }
    int maxi=-1;
    int idx=-1;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            maxi=arr[i];
            idx=i;
        }
    }
    char ans=idx+'a';
    return ans;
}

int main(){
    cout<<maxOccuringCharacter("soumyas");
    return 0;
}
