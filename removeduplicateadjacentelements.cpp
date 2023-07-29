#include<iostream>

using namespace std;

/*You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.*/

string removeDuplicates(string s) {
       string Result="";
       Result=s[0];
       for( int i=1;i<s.size();i++){
         if(s[i]==Result.back()){
          Result.pop_back();
         }
         else {
           Result.push_back(s[i]);
         }
       }
       return Result;
    }

int main(){
    
    return 0;
}
