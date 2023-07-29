#include <iostream>

using namespace std;

void sayDigits(int n, string arr[])
{
    // base condition
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;
    sayDigits(n, arr); // Recursive call

    cout << arr[digit] << " "; // this will get executed for every function from the stack once the function is terminated and the stack starts getting empty
}

int main()
{
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout<<"Enter the digit:";
    int digit;
    cin>>digit;
    sayDigits(digit, arr);
    return 0;
}
