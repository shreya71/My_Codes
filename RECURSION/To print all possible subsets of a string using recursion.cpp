/******************************************************************************
p, q, r, s 
pos 
0    1     2    3 
p    q     r    s 

two possibilities
either exclude a letter or include it
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
void print(string n, int pos, string s = "")
{
    if(pos == n.length())
    {
        cout << s << endl;
    return;
    }
    print(n, pos+1, s+n[pos]);
    print(n, pos+1, s);
}
int main()
{
    string n;
    cin >> n;
    int pos = 0;
    string s;
    print(n, pos, s);

    return 0;
}