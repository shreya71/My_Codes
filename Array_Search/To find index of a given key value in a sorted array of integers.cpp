#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int n, int key)
{
    int s = 0, e = n;
    while(s <= e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == key )
        return mid;
        else if(arr[(s+e)/2] < key )
        s = mid+1;
        else
        e = mid-1;
    }
    return -1;
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for(int i =0; i<n; i++)
   {
        cin >> arr[i] ;
   }
   int key;
   cin >> key;
   int p = binary_search(arr, n, key);
   cout << p << endl;
}