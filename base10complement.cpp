#include <iostream>

using namespace std;

// This program is for finding the compliment of a number, where we will compliment the bits of the number till its largest place
int complement(int x)
{
    if (x == 0)
    {
        return 1;
    }
    int mask = 0;
    int alias = x;
    while (alias != 0)
    {
        mask = mask << 1;
        mask = mask | 1;
        alias = alias >> 1;
    }
    //After this, mask will be equal to 000...111 (1s will start from where the digit is actually starting)
    x = ~x;
    int ans = x & mask;
    return ans;
}

int main()
{
    cout << complement(5);
    return 0;
}
