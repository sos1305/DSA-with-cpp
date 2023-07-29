#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    array<int, 4> a = {1, 2, 3, 4};
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << "Element at 2nd index: " << a.at(2) << endl;
    cout << "Empty or not: " << a.empty() << endl;
    cout << "First element:" << a.front() << endl;
    cout << "Last element:" << a.back() << endl;

    cout << "\n\n\t\tVECTORS\n\n\n";
    vector<int> v;
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    v.push_back(1);
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    v.push_back(2);
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    v.push_back(3);
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    v.push_back(4);
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;
    v.shrink_to_fit();
    cout << "Capacity->" << v.capacity() << endl;
    cout << "Size->" << v.size() << endl;

    vector<int> x(5, 1);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    vector<int> y = {1, 2, 3, 4, 5};
    for (int i = 0; i < y.size(); i++)
    {
        cout << y[i] << " ";
    }
    cout << endl
         << endl;
    cout << "\t\tSET\n";
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(6);
    s.insert(4);
    s.insert(0);
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    set<int>::iterator it = s.begin(); // it is a pointer pointing to the index of the element
    it++;
    s.erase(it);
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s.count(5);
    set<int>::iterator itr = s.find(5);
    for (auto it = itr; it != s.end(); it++)
    {
        cout << endl
             << *it;
    }

    cout << "\n\n\n\t\tMaps\n";
    map<int, string> m;
    m[1] = "soumya";
    m[13] = "baller";
    m[2] = "shubham";
    m.insert({5, "unlucky"});
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "Finding whether 13 is there or not:" << m.count(13) << endl;
    cout << "Before erase:\n";
    for (auto i : m)
    {
        cout << i.first << endl;
    }
    m.erase(13);
    cout << "After erase:\n";
    for (auto i : m)
    {
        cout << i.first << endl;
    }
    auto iter = m.find(2);
    cout << (*iter).second;
    return 0;
}
