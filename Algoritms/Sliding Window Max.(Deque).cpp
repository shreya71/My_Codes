/* SLIDING WINDOW MAXIMUM
                arr = 1, 3, -1, -3, 5, 3, 6, 7
                k = 3,
                so for every 3 consecutive indices we have to find max
                expected o/p -> 3, 3, 5, 5, 6, 7

APPROACH:
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(auto &i: a)
    cin >> i;
    deque<int> dq;
    vector<int> v;
    for(int i = 0; i < k ; i++)
    {
        while(!dq.empty() && a[dq.back()] < a[i])
        dq.pop_back();
        dq.push_back(i);
    }
    v.push_back(a[dq.front()]);
    for(int i = k; i < n ; i++)
    {
        if(dq.front() == i-k)
        dq.pop_front();
        while(!dq.empty() && a[dq.back()] < a[i])
        dq.pop_back();
        dq.push_back(i);
        v.push_back(a[dq.front()]);
    }
    
    for(auto i : v)
    cout << i << " ";
}
