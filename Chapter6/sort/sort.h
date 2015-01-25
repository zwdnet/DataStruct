#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <iostream>
#include <vector>

//≤Â»Î≈≈–Ú
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

//shell≈≈–Ú
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

//∂—≈≈–Ú
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


#endif // SORT_H_INCLUDED
