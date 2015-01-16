#ifndef TOOL_H
#define TOOL_H
//���ݽṹѧϰ���ߺ���
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

//�����������,����ֵ��Ϊ[a,b]��Ĭ��Ϊ[0,10]��
template <typename T>
void GenerateData(vector<T> & data, const int N, const int a = 0, const int b = 10)
{
    if (N <= 0)
    {
        return;
    }
    srand(time(0));
    int define = b-a+1;
    for (int i = 0; i < N; i++)
    {
        int t = rand()%define;
        t += a;
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

//���������Ϣ
void Error(string s)
{
    cout<<s;
}
#endif
