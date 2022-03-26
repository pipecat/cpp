#include <iostream>
using namespace std;

class Stack
{
private:
    int data[10];
    int top;
public:
    bool empty();

    Stack();
    // ~Stack();
};

Stack::Stack()
{
    top = 0;
}

inline bool
Stack::empty()
{
    return top>0?true:false;
}