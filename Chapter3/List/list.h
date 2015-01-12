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
    void Insert(T x, Node<T>* pos)
    {
        Node<T>* TmpCell;
        TmpCell = new Node<T>;
        if (TmpCell == NULL)
        {
            cout<<"ÄÚ´æÒç³ö"<<endl;
            exit(1);
        }

        TmpCell->Element = x;
        TmpCell->Next = pos->Next;
        pos->Next = TmpCell;
    }
    void DeleteList();
    T Retieve(Node<T>* p);

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
