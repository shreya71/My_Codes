/*
QUEUE: Stores a list of items in which an item can be inserted at one end and removed from the other end only. 
       FIFO first in first outer
    OPERATIONS: enqueue(x) -> insert from back
                dequeue() -> remove from front
                peek() -> returns top element that is at front which gets removed
                empty() -> tells whther queue is empty or not
                
*/


// IMPLEMENTATION USING ARRAY

#include <iostream>
using namespace std;

#define n 20

class queue{
    int* arr;
    int front, back;
    
    public:
    queue()            // constructor
    {
        arr = new int[n];
        front = -1;
        back  = -1;
    }
    
    void push(int x)
    {
        if(back == n-1)                               // back already at end no space in queue
        {
            cout << "queue overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if(front == -1)                              // in case of adding first element we need to frint to o index
        front++;
    }
    void pop()
    {
        if(front == -1 || front > back){             
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if(front == -1 || front > back){
            cout << "No elements in queue" << endl;
            return -1;
    }
    return arr[front];
    }
    bool empty()
    {
        if(front == -1 || front > back)
        return 1;
        return false;
    }
};
int main()
{
    queue q;                                      // 1          5       7       1
    q.push(1);                                  //front(peek)                 back
    q.push(5);
    q.push(7);
    q.push(1);
    cout << q.peek() << endl;                    
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
