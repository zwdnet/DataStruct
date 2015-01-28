#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <vector>

//插入排序
template <typename T>
void InsertSort(vector<T> & data)
{
    int N = data.size();

    int j, p;

    T temp;
    for (p = 1; p < N; p++)
    {
        temp = data[p];
        for (j = p; j > 0 && data[j-1] > temp; j--)
        {
            data[j] = data[j-1];
        }
        data[j] = temp;
    }
}

//shell排序
template <typename T>
void ShellSort(vector<T> & data)
{
    int N = data.size();
    int i, j, Increment;
    T temp;

    for (Increment = N/2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < N; i++)
        {
            temp = data[i];
            for (j = i; j >= Increment; j -= Increment)
            {
                if (temp < data[j - Increment])
                {
                    data[j] = data[j - Increment];
                }
                else
                {
                    break;
                }
            }
            data[j] = temp;
        }
    }
}

//堆排序
int LeftChild(int i)
{
    return 2*i + 1;
}

template <typename T>
void PercDown(vector<T> & data, int i, int N)
{
    int Child;
    T temp;

    for (temp = data[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N-1 && data[Child + 1] > data[Child])
        {
            Child++;
        }
        if (temp < data[Child])
        {
            data[i] = data[Child];
        }
        else
        {
            break;
        }
    }
    data[i] = temp;
}

template <typename T>
void HeapSort(vector<T> & data)
{
    int i;
    int N = data.size();

    for (i = N/2; i >= 0; i--)
    {
        PercDown(data, i, N);
    }
    for (i = N-1; i > 0; i--)
    {
        T temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        PercDown(data, 0, i);
    }
}

//归并排序
//合并过程
template <typename T>
void Merge(vector<T> & data, vector<T> & TmpArray, int Lpos,
            int Rpos, int RightEnd)
{
    int i, LeftEnd, NumElements, TmpPos;

    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    while (Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if (data[Lpos] <= data[Rpos])
        {
            TmpArray[TmpPos++] = data[Lpos++];
        }
        else
        {
            TmpArray[TmpPos++] = data[Rpos++];
        }
    }

    while (Lpos <= LeftEnd)
    {
        TmpArray[TmpPos++] = data[Lpos++];
    }
    while (Rpos <= RightEnd)
    {
        TmpArray[TmpPos++] = data[Rpos++];
    }

    for (i = 0; i < NumElements; i++, RightEnd--)
    {
        data[RightEnd] = TmpArray[RightEnd];
    }
}

//实际排序过程
template <typename T>
void MSort(vector<T> & data, vector<T> & TmpArray, const int & Left,
           const int & Right)
{
    int Center;

    if (Left < Right)
    {
        Center = (Left + Right)/2;
        MSort(data, TmpArray, Left, Center);
        MSort(data, TmpArray, Center+1, Right);
        Merge(data, TmpArray, Left, Center+1, Right);
    }
}

template <typename T>
void MergeSort(vector<T> & data)
{
    vector<T> TmpArray;
    TmpArray.resize(data.size());
    MSort(data, TmpArray, 0, data.size()-1);
}

//快速排序
template <typename T>
T Median3(vector<T> & data, int Left, int Right)
{
    int Center = (Left + Right) / 3;

    if (data[Left] > data[Center])
    {
        swap(data[Left], data[Center]);
    }
    if (data[Left] > data[Right])
    {
        swap(data[Left], data[Right]);
    }
    if (data[Center] > data[Right])
    {
        swap(data[Center], data[Right]);
    }

    swap(data[Center], data[Right-1]);
    return data[Right-1];
}

//专门给快排用的插入排序
template <typename T>
void InsertSort(vector<T> & data, int Left ,int Right)
{
    int N = Right-Left+1;

    int j, p;

    T temp;
    for (p = Left; p < N; p++)
    {
        temp = data[p];
        for (j = p; j > 0 && data[j-1] > temp; j--)
        {
            data[j] = data[j-1];
        }
        data[j] = temp;
    }
}

const int Cutoff = 3;

template <typename T>
void Qsort(vector<T> & data, int Left, int Right)
{
    int i, j;
    T Pivot;

    if (Left + Cutoff <= Right)
    {
        Pivot = Median3(data, Left, Right);
        i = Left, j = Right-1;
        for (;;)
        {
            while (data[++i] < Pivot){}
            while (data[--j] > Pivot){}
            if (i < j)
            {
                swap(data[i], data[j]);
            }
            else
            {
                break;
            }
        }
        swap(data[i], data[Right-1]);

        Qsort(data, Left, i-1);
        Qsort(data, i+1, Right);
    }
    else
    {
        InsertSort(data, Left, Right-Left+1);
    }
}

template <typename T>
void QuickSort(vector<T> & data)
{
    int N = data.size();
    Qsort(data, 0, N-1);
}

#endif // SORT_H_INCLUDED
