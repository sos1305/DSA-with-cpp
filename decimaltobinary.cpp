#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    bitset<32> binary(decimal);
    cout << "Binary equivalent: " << binary << endl;
    return 0;
}
