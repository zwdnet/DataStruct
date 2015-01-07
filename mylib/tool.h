#ifndef TOOL_H
#define TOOL_H
//���ݽṹѧϰ���ߺ���
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

//�����������
template <typename T>
void GenerateData(vector<T> & data, const int N)
{
    if (N <= 0)
    {
        return;
    }
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        int t = rand()%N+1;
        data.push_back(t);
    }
}

//�������
template <typename T>
void DisplayData(const vector<T> & data)
{
    int N = data.size();
    for (int i = 0; i < N; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
#endif
