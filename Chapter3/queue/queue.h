#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
//队列的数组实现
#include <iostream>
#include <vector>
#include "../../mylib/tool.h"

using namespace std;

template <typename T>
class Queue
{
    private:
        int capacity; //队列容量
        int front;    //队头
        int rear;     //队尾
        int size;     //队列大小
        vector<T> Array; //对列数据
    public:
        Queue(void)
        {
            size = 0;
            front = 1;
            rear = 0;
            capacity = 5;
            Array.reserve(capacity);
        }
        Queue(int maxCapacity)
        {
            size = 0;
            front = 1;
            rear = 0;
            if (maxCapacity <= 0)
            {
                maxCapacity = 5;
            }
            capacity = maxCapacity;
            Array.reserve(capacity);
        }
        bool IsEmpty();
        bool IsFull();
        void DisposeQueue(void);
        void MakeEmpty(void);
        void Enqueue(T x);
        T Front(void);
        void Dequeue(void);
        T FrontAndDequeue(void);
};

template <typename T>
bool Queue<T>::IsEmpty(void)
{
    return size == 0;
}

template <typename T>
bool Queue<T>::IsFull(void)
{
    return size == capacity;
}

template <typename T>
void Queue<T>::MakeEmpty(void)
{
    size = 0;
    front = 1;
    rear = 0;
    Array.clear();
}

template <typename T>
void Queue<T>::Enqueue(T x)
{
    if (IsFull())
    {
        Error("Full Equeue\n");
    }
    else
    {
        size++;
        if (++rear == capacity)
        {
            rear = 0;
        }
        Array[rear] = x;
    }
}

template <typename T>
T Queue<T>::Front(void)
{
    if (IsEmpty())
    {
        return NULL;
    }
    return Array[front];
}

template <typename T>
void Queue<T>::Dequeue(void)
{
    if (IsEmpty())
    {
        Error("Empty queue\n");
        return;
    }
    if (front == rear)
    {
        return;
    }
    else
    {
        size--;
        front++;
    }
}

#endif // QUEUE_H_INCLUDED
