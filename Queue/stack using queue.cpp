// STACK USING QUEUE (2 approaches)


// Approach 1 : using 2 queues n push is costly

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){
        N = 0;
    }

    void push(int val)                                  // push for stack
    {
        q2.push(val);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;                         // swapping q1 n q2
        q1 = q2;
        q2 = temp;
    }
    void pop()                                        
    {
        q1.pop();
        N--;
    } 
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return N;
    }
};
int main()
{
    Stack s;                                      //  2         5       7       8
    s.push(2);                                  //   back                      top
    s.push(5);
    s.push(7);
    s.push(8);
    cout << s.top() << endl;                    
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl; 
    return 0;
}


// Approach 2 : using 2 queues n pop is costly

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){
        N = 0;
    }
    void pop()                                 
    {
        if(q1.empty())
        return;
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q1;                        
        q1 = q2;
        q2 = temp;
    }
   void push(int val)                                        
    {
        q1.push(val);
        N++;
    } 
    int top()
    {
        if(q1.empty())
        return -1;
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans =  q1.front();
        q2.push(ans);
         queue<int> temp = q1;                        
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size()
    {
        return N;
    }
};
int main()
{
    Stack s;                                      //  2         5       7       8
    s.push(2);                                  //   back                      top
    s.push(5);
    s.push(7);
    s.push(8);
    cout << s.top() << endl;                    
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl; 
    return 0;
}
