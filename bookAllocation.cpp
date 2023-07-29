#include <iostream>

using namespace std;
// The book allocation problem is to allocate i number of books (index of array) to m students such that:
// 1. Each student should must have at least 1 book
// 2. The maximum of total pages allocated to the students should be minimum when considering all the approaches
// 3. The books should must be allocated in a constant manner

bool isPossible(int arr[], int n, int m, int middle)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= middle)
        { // We're comparing sum of pages till a certain limit to the middle value.
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > middle)
            { // If extra students are needed to distribute the books to have minimum pages or if pages of a book is greater than the middle value, then the books won't be distributed according to the condition. So, we return false.
                return false;
            }
            pageSum = arr[i]; // page distribution for the next student
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m)
{
    if(m>n)
    {
        return -1;
    }
    int start = 0;
    int totalPages = 0;
    for (int i = 0; i < n; i++)
    {
        totalPages += arr[i];
    }
    int end = totalPages;
    int middle = (start + end) / 2;
    int ans = -1;   
    while (start <= end)
    {
        if (isPossible(arr, n, m, middle))
        {                     // If the page distribution is possible
            ans = middle;     // Potential to be the answer
            end = middle - 1; // So that we can find the minimum answer
        }
        else
        {
            start = middle + 1; // Insufficient pages, so we check afterwards
        }
        middle = (start + end) / 2;
    }
    return ans;
}

int main()
{
    int books[] = {10,20,30,40};
    cout << allocateBooks(books, 4, 2);
    return 0;
}
