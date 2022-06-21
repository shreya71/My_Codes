// QUEUE USING STACK (2 approaches)


// Approach 1 : using 2 stacks n dequeue

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class que{
    stack<int> s1;
    stack<int> s2;
    
    public:

    void push(int x)                                  // enqueue
    {
        s1.push(x);
    }
    int pop()                                        // dequeue && also returning peek value of queue
    {
        if(s1.empty() && s2.empty()){             
            cout << "No elements in queue" << endl;
            return -1;
        }
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    } 
    bool empty()                                       // empty check for queue
    {
        if(s1.empty() && s2.empty())
        return 1;
        return false;
    }
};
int main()
{
    que q;                                      //  2         5       7       8
    q.push(2);                                  //front(peek)                 back
    q.push(5);
    q.push(7);
    q.push(8);
    cout << q.pop() << endl;                    
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    cout << q.pop() << endl; 
    cout << q.empty() << endl;
    cout << q.pop() << endl; 
    return 0;
}



// Approach 2 : using one created stack and one existing call stack (better)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class que{                                                          // confuses in user defined n inbuilt queue
    stack<int> s1;
    
    public:

    void push(int x)                                  // enqueue
    {
        s1.push(x);
    }
    int pop()                                        // dequeue && also returning peek value of queue
    {
        if(s1.empty()){             
            cout << "No elements in queue" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        
        if(s1.empty())
        return x;
        int item = pop();
        s1.push(x);
        return item;
    } 
    bool empty()                                       // empty check for queue
    {
        if(s1.empty())
        return 1;
        return false;
    }
};
int main()
{
    que q;                                      //  2         5       7       8
    q.push(2);                                  //front(peek)                 back
    q.push(5);
    q.push(7);
    q.push(8);
    cout << q.pop() << endl;                    
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    cout << q.pop() << endl; 
    cout << q.empty() << endl;
    cout << q.pop() << endl; 
    return 0;
}
