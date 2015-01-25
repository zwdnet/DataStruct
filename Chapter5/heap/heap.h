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
        HeapStruct<T> * HeapHead;

    private:
        HeapStruct<T> * initialize(const int MaxElements);

    public:
        Heap(const int MaxElements){Initialize(MaxElements);}
        void Initialize(const int MaxElements){HeapHead = initialize(MaxElements);}
        void Destroy(void);
        void MakeEmpty(void);
        void Insert(const T x);
        T DeleteMin(void);
        T FindMin(void){return HeapHead->Elements[1];};
        bool IsEmpty(void){return HeapHead->Size == 0;}
        bool IsFull(void){return HeapHead->Size == HeapHead->Capacity;}
        void BuildHeap(vector<T> x);
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

template <typename T>
void Heap<T>::Insert(T x)
{
    int i = 0;

    if (IsFull())
    {
        cout<<"堆已满"<<endl;
        return;
    }

    for (i = ++HeapHead->Size; HeapHead->Elements[i/2] > x; i /= 2)
    {
        HeapHead->Elements[i] = HeapHead->Elements[i/2];
    }
    HeapHead->Elements[i] = x;
}

template <typename T>
T Heap<T>::DeleteMin(void)
{
    int i, Child;
    T MinElement, LastElement;

    if (IsEmpty())
    {
        cout<<"堆为空"<<endl;
        return HeapHead->Elements[0];
    }

    MinElement = HeapHead->Elements[1];
    LastElement = HeapHead->Elements[HeapHead->Size--];

    for (i = 1; i*2 <= HeapHead->Size; i = Child)
    {
        Child = i*2;
        if (Child != HeapHead->Size && HeapHead->Elements[Child + 1]
                                       < HeapHead->Elements[Child])
        {
            Child++;
        }
        if (LastElement > HeapHead->Elements[Child])
        {
            HeapHead->Elements[i] = HeapHead->Elements[Child];
        }
        else
        {
            break;
        }
    }
    HeapHead->Elements[i] = LastElement;
    return MinElement;
}

template <typename T>
void Heap<T>::BuildHeap(vector<T> x)
{
    int N = x.size();
    for (int i = 0; i < N; i++)
    {
        Insert(x[i]);
    }
}
#endif // HEAP_H_INCLUDED
