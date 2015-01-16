#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    cout<<queue.IsEmpty()<<endl;
    cout<<queue.IsFull()<<endl;
    cout<<queue.Front()<<endl;
    queue.Dequeue();
    cout<<queue.Front()<<endl;
    return 0;
}
