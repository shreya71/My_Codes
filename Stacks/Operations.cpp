/***************************************************************************************************************
Operations with a time complexity of O(N)
1. push(x)
2. pop()
3. top()
4. empty()
****************************************************************************************************************/

#include <iostream>
using namespace std;
#define n 100                             //predefined n
class stack
{
    int* A;                              //dynamic array
    int top;
    public:
    stack()                               //constructor for stack
    {
        A = new int[n];                   // allocating memory to array
        top = -1;
    }
    
    void push(int x)                      // push operation in stack
    {
        if(top == n-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        A[top] = x;
    }
    
    void pop()                               // Pop operation in stack
    {
        if(top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    
    int At_Top()                                 // Top operation of stack
    {
       if(top == -1)
        {
            cout << "No top element in stack" << endl;
            return -1;
        } 
        return A[top];
    }
    
    bool empty()                                      // empty operation of stack
    {
        return top == -1 ;                           // returns true when stack is empty
    }
};

int main()
{
    stack s;                                       // class created
    s.push(1);
    cout << s.At_Top() << endl;
    s.push(2);
    cout << s.At_Top() << endl;
    s.push(7);
    cout << s.At_Top() << endl;
    s.push(8);
    cout << s.At_Top() << endl;                      // should give 8
    s.pop();
    cout << s.At_Top() << endl;                      // should give 7
    s.pop();
    cout << s.empty() << endl;                   // False
    s.pop();
    s.pop();
    cout << s.empty() << endl;                   // True
    s.pop();
    cout << s.empty() << endl;                   // Error
}
