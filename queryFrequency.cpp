#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements which you want to enter: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> v[i];
    }
    const int N = 1e5 + 10;
    vector<int> freq(N, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    int noOfQueries;
    cout << "Enter your number of queries: ";
    cin >> noOfQueries;
    while (noOfQueries != 0)
    {
        int ele;
        cout << "Enter the element to get its frequency: ";
        cin >> ele;
        cout << "The frequency of " << ele << " is " << freq[ele] << endl;
        noOfQueries--;
    }
    return 0;
}
