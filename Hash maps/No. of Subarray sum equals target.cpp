/*************************************************************************************************
We take the sum of all elemnets before index i and check whether it is equal to target or not.
secondly we check whether sum-target is present or not.......if yes we add the count of sum-target
we have created a map storing the prefix sum as key and its occurences as its value.

****************************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin >>n;
    int A[n];
    for(int i = 0; i< n ; i++)
    {
        cin >> A[i];
    }
    int target, sum = 0, count = 0;
    cin >> target;
    map<int, int> m;
    for(int i = 0; i< n ; i++)
    {
        sum += A[i];
        if(sum == target)
        count++;
        if(m.find(sum-target) != m.end())
        count += m[sum-target] ;
        m[sum]++;
    }
    cout << count << endl;
}
