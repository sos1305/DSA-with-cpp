#include <iostream>
#include <cmath>
using namespace std;

int bintodec(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n % 10;
        if (bit == 1)
        {
            ans = ans + pow(2, i);
        }
        i++;
        n = n / 10;
    }
    return ans;
}

int main()
{
    cout<<"The number is "<<bintodec(110);
    return 0;
}
