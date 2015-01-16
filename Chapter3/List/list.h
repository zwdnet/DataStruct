#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <typename T>
struct Node
{
    T Element;
    Node * Next;
    Node()
    {
        Element = 0;
        Next = NULL;
    }
    ~Node()
    {
    }
};

template <typename T>
class List
{
private:
    Node<T> * head;
    int size;

public:
    List();
    ~List();
    void MakeEmpty(void);
    bool IsEmpty(void);
    bool IsLast(Node<T>* pos);
    int Find(T x);
    int Size(void)
    {
        return size;
    }
    void Delete(T x)
    {
        Node<T>* p, TempCell;
        p = FindPrevious(x);
        if (!IsLast(p))
        {
            TempCell = p->Next;
            p->Next = TempCell->Next;
            delete TempCell;
        }
    }
    void Insert(T x, int t)
    {
        Node<T> * pos = head;
        /*
        if (t > size)
        {
            cout<<"位置有误"<<endl;
            return;
        }
        */
        for (int i = 0; i < t; i++)
        {
            pos = pos->Next;
        }
        Node<T>* TmpCell;
        TmpCell = new Node<T>;
        if (TmpCell == NULL)
        {
            cout<<"ÄÚ´æÒç³ö"<<endl;
            exit(1);
        }

        TmpCell->Element = x;
        if (size == 0)
        {
            TmpCell->Next = NULL;
        }
        else
        {
            TmpCell->Next = pos->Next;
            pos->Next = TmpCell;
        }

    }
    T get(int i)
    {
        Node<T> *p = head;
        int j = 0;
        if (size == 0 || i >= size)
        {
            return NULL;
        }
        do
        {
            p = p->Next;
            if (i == j)
            {
                return p->Element;
            }
            j++;
        }while (j < size);
        return NULL;
    }
    void DeleteList();

    //递归查找 程序有错
    //递归调用的函数
    int FindNext(Node<T> * p, T x)
    {
        if (p == NULL)
        {
            return -1;
        }
        else if (p->Element == x)
        {
            return 1;
        }
        else
        {
            return FindNext(p->Next, x);
        }
    }

    //链表逆置
    void Reverse(void)
    {
        Node<T> * p = head;
        if (NULL == p)
        {
            return;
        }
        Node<T> * pPrev = NULL;
        Node<T> * pNext = NULL;
        while (NULL != p)
        {
            pNext = p->Next;
            if (NULL == pNext)
            {
                head = p;
            }
            p->Next = pPrev;
            pPrev = p;
            p = pNext;
        }
    }

    //主函数
    int FindR(T x)
    {
        Node<T>* p;
        p = head->Next;
        int i = 0;
        if (p->Element != x)
        {
            if (p->Next == NULL)
            {
                i = -1;
            }
            else
            {
                i = i + FindNext(p->Next, x);
            }
        }
        return i;
    }

private:
    Node<T>* FindPrevious(T x)
    {
        Node<T>* p;
        p = head;
        while (p->Next != NULL && p->Next->Element != x)
        {
            p = p->Next;
        }
        return p;
    }
    Node<T>* Header();
    Node<T>* First();
    Node<T>* Advance(Node<T>* p);
};

template <typename T>
List<T>::List()
{
    head = NULL;
    size = 0;
}

template <typename T>
List<T>::~List()
{

}

template <typename T>
bool List<T>::IsEmpty()
{
    return size == 0;
}

template <typename T>
bool List<T>::IsLast(Node<T>* pos)
{
    return pos->Next == NULL;
}

template <typename T>
int List<T>::Find(T x)
{
    Node<T>* p;
    p = head->Next;
    int i = 0;
    while (p != NULL && p->Element != x)
    {
        p = p->Next;
        i++;
    }
    return i;
}

#endif
