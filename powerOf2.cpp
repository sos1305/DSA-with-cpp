#include <iostream>
#include <cmath>
using namespace std;

bool powerof2(int n)
{
    for (int i = 0; i <= 30; i++) //We did that because in C++, the range of integers is from -2^31 to 2^31 - 1
    {
        if (n == pow(2, i))
        {
            return true;
        }
        if(n < pow(2, i))
        {
            return false;
        }
    }
}

int main()
{
    cout << powerof2(1024);
    return 0;
}
