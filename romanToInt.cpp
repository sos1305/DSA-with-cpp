#include<iostream>

using namespace std;

    int romanConverter(char x){
        switch(x){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
        }
    }

    int romanToInt(string s) {
    int result = 0;
    int num_last = 0;
    int num_this = 0;
    for (int i = s.size() -1; i >= 0; i--) {
        num_this = romanConverter(s[i]);
        num_this < num_last?  result -= num_this: result += num_this;
        num_last = num_this;
    }
    return result;
    }

int main(){
    cout<<romanToInt("XIV");
    return 0;
}
