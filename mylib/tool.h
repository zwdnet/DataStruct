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
    data.clear(); //��ֹ�û���������������ĳ��ȣ�����push_back�����ӳ��ȣ��������õ��ĳ���Ϊ2N
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

//��������
template <typename T>
void CopyData(const vector<T> & Origin, vector<T> & Dest)
{
    int N = Origin.size();
    Dest.resize(N);
    for (int i = 0; i < N; i++)
    {
        Dest[i] = Origin[i];
    }
}
#endif
