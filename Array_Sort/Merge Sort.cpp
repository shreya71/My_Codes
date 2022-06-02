#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int mid, int r)
{
   // storing elements into two temporary arrays then sortinf as well as combining simultaneously
   int n1 = mid - l +1, n2 = r - mid;
   int a1[n1], a2[n2] ;
   for(int i = 0; i<n1; i++)
   {
       a1[i] = a[i+l];
   }
   for(int i = 0; i<n2; i++)
   {
       a2[i] = a[i+mid+1];
   }
   int i = 0, j = 0, k =l ;
   while(i<n1 && j < n2)
   {
       if(a1[i] < a2[j])
       {
           a[k] = a1[i];
           i++; k++;
       }
       else
       {
           a[k] = a2[j];
           j++; k++;
       }
   }
    while(i < n1)
    {
        a[k] = a1[i];
         i++; k++;
    }
    while(j < n2)
    {
        a[k] = a2[j];
           j++; k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2 ;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}
int main()
{
   int n ;
   cin >> n ;
   int a[n];
   for(int i = 0; i<n; i++)
   {
       cin >> a[i] ;
   }
   int l = 0, r =n-1;
   mergeSort(a, l, r);
   for(int i = 0; i<n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
