#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
struct HeapStruct
{
        int Capacity;
        int Size;
        T * Elements;
};

template <typename T>
class Heap
{
    private:
        HeapStruct<T> * HeapNode;

    private:
        HeapStruct<T> * initialize(const int MaxElements);

    public:
        void Initialize(const int MaxElements){initialize(MaxElements);}
        void Destroy(void);
        void MakeEmpty(void);
        void Insert(const T x);
        T DeleteMin(void);
        T FindMin(void);
        bool IsEmpty(void);
        bool IsFull(void);
};

template <typename T>
HeapStruct<T> * Heap<T>::initialize(const int MaxElements)
{
    HeapStruct<T> * H;
    /*
    if (MaxElements < MinPZSize)
    {
        cout<<"优先队列大小太小"<<endl;
    }
    */

    H = new HeapStruct<T>;
    if (H == NULL)
    {
        cout<<"内存分配出错"<<endl;
    }

    H->Elements = new T[MaxElements + 1];
    if (H->Elements == NULL)
    {
        cout<<"内存分配出错"<<endl;
    }

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = 0;

    return H;
}


#endif // HEAP_H_INCLUDED
