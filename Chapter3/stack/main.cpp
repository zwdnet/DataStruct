#include <iostream>
#include "stack.h"
#include "../../mylib/tool.h"
#// µœ÷’ª

using namespace std;

int main()
{
    //LinkStack<int> StackTest;
    ArrayStack<int> StackTest;
    cout<<StackTest.IsEmpty()<<endl;
    for (int i = 0; i < 10; i++)
    {
        StackTest.Push(i*i);
    }
    cout<<StackTest.Top()<<endl;
    StackTest.Pop();
    StackTest.Pop();
    cout<<StackTest.Top()<<endl;
    StackTest.MakeEmpty();
    cout<<StackTest.IsEmpty()<<endl;
    return 0;
}
