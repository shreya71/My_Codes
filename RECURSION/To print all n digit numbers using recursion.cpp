/******************************************************************************

pos
 0      1     2
 -      -     - 
 1-9   0-9   0-9

here since n = 3.......
pos will go up to 2 then the base case will limit pos which should be less than 3 

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
void print(int n, int pos, string s = "")
{
    if(pos == n)
    {
        cout << s << endl;
    return;
    }
    for(int i = 0; i<=9; i++)
    {
        if(pos == 0 && i == 0)
        continue;
        print( n, pos+1, s+to_string(i) );
    }
}
int main()
{
    int n;
    cin >> n;
    int pos = 0;
    string s;
    print(n, pos, s);

    return 0;
}