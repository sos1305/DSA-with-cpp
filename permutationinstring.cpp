#include <iostream>
/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.*/

using namespace std;
bool checkIfSame(char a1[], char a2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (a1[i] != a2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    char s1cnt[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        char ch = s1[i];
        int idx = ch - 'a';
        s1cnt[idx]++;
    }

    char s2window[26] = {0}; // window count
    int i = 0;
    while (i < s1.length() && i < s2.length())
    {
        char ch = s2[i];
        int idx = ch - 'a';
        s2window[idx]++;
        i++;
    }
    if (checkIfSame(s1cnt, s2window))
    {
        return true;
    }
    while (i < s2.length())
    {
        char newch = s2[i];
        int idx = newch - 'a';
        s2window[idx]++;
        char oldch = s2[i - s1.length()];
        idx = oldch - 'a';
        s2window[idx]--;

        if (checkIfSame(s1cnt, s2window))
        {
            return true;
        }
        i++;
    }
    return false;
}
int main()
{
    cout<<checkInclusion("ay","Soumya");
    return 0;
}
