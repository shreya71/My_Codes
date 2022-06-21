/*
          DEQUE:    Mixture of stacks and queues
                    It performs both FIFO and LIFO or even LILO, FILO          
*/          

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(5);
    dq.push_front(7);
    dq.push_front(8);
    for(auto i : dq)
    cout << i << " ";
    cout << endl;
    dq.pop_back();
    dq.pop_back();
    dq.pop_front();
     for(auto i : dq)
    cout << i << " ";
    cout << endl;
}
