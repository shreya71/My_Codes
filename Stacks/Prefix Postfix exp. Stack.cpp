#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int postfix(string s)
{
    stack<int> st; 
    for(int i = 0; i< s.length(); i++)
    {
        if(isspace(s[i]))
        continue;
        else if(isdigit(s[i]))
        st.push(s[i]-'0');
        else
        {
            int o1 = st.top();
            st.pop();
            int o2 = st.top(), r = 0;
            st.pop();
            if(s[i] == '+')
             r = o1 + o2 ;
            else if(s[i] == '-')
             r = o2 - o1 ;
            else if(s[i] == '*')
             r = o2 * o1 ;
            else if(s[i] == '/')
             r = o2 / o1 ;
            st.push(r);
        }
    }
    return st.top();
}
int prefix(string s)
{
    stack<int> st;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(isspace(s[i]))
        continue;
        else if(isdigit(s[i]))
        st.push(s[i]-'0');
        else
        {
            int o1 = st.top();
            st.pop();
            int o2 = st.top(), r = 0;
            st.pop();
            if(s[i] == '+')
             r = o1 + o2 ;
            else if(s[i] == '-')
             r = o1 - o2 ;
            else if(s[i] == '*')
             r = o2 * o1 ;
            else if(s[i] == '/')
             r = o1 / o2 ;
            st.push(r);
        }
    }
    return st.top();
}
int main()
{
    string s = "4 6 + 2 / 5 * 7 +" ;
    string s1 = "- + 7 * 4 5 + 2 0" ;
        cout << "Postfix " << postfix(s) << endl ;
        cout << "Prefix " << prefix(s1) << endl ;
}
