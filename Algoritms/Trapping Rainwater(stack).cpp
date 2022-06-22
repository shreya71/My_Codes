/******************************************************************************
                         TRAPPING RAINWATER HARVESTING
                         
QUESTION: Given non-negative integers representing an elevation map where width of each bar is 1,
          compute how much water it can trap after raining.
          
APPROACH:           
*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rain_water(vector<int> a)
{
    stack<int> s;
    int n = a.size(), ans = 0;
    for(int i = 0; i< n; i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            int cur = s.top();
        s.pop();
        if(s.empty())
        break;
        int diff = i - s.top() - 1;
        ans += (min(a[s.top()], a[i])- a[cur]) * diff ;
    }
    s.push(i);
    }
    return ans;
}
int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1} ;
    cout << rain_water(v) << endl;
}
