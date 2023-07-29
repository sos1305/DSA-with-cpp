#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/

int compress(vector<char>& chars) {
        int i=0;
        int ansIndex=0;
        int n=chars.size();

        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }// to get the index of last occurence of the element
            int count=j-i; //to get the number of occurences of the element
            chars[ansIndex]=chars[i];//to write the element name
            ansIndex++;
            if(count>1){
                string cnt=to_string(count);
                for(char ch:cnt){
                    chars[ansIndex]=ch;//to write the element occurences
                    ansIndex++;
                }
            }
            i=j; //For next sequence of characters
        }
        return ansIndex;
    }

int main(){
    
    return 0;
}
