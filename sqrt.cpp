#include <iostream>
// This program is to find the square root of a number using binary search. If the square root is in decimal, we will return only the integer part.
using namespace std;

long long int sqrtInt(int n)
{
    int start = 0;
    int end = n;
    long long int ans = -1;
    long long int middle = (start + end) / 2;
    while (start <= end)
    {
        long long int square = middle * middle;
        if (square == n)
        {
            return middle;
        }
        else if (square < n)
        {
            ans = middle;
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
    return ans;
}

double sqrt(int n, int precision, int IntegerPart)
{
    double factor = 1;
    double ans = IntegerPart;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number to print its square root: ";
    cin >> n;
    int temp = sqrtInt(n);
    cout << "The square root of " << n << " is " << sqrt(n, 3, temp);
    return 0;
}
