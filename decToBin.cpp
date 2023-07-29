#include <iostream>
#include <cmath>
using namespace std;

int dectobin(int n)
{
    int answer = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n & 1;
        answer = answer + (digit * pow(10, i));
        i++;
        n = n >> 1;
    }
    return answer;
}

int main()
{
    cout << "The answer is " << dectobin(5);
    return 0;
}
