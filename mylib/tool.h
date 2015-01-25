#ifndef TOOL_H
#define TOOL_H
//数据结构学习工具函数
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

//产生随机数据,数据值域为[a,b]，默认为[0,10]。
template <typename T>
void GenerateData(vector<T> & data, const int N, const int a = 0, const int b = 10)
{
    if (N <= 0)
    {
        return;
    }
    data.clear(); //防止用户事先声明了数组的长度，下面push_back会增加长度，导致最后得到的长度为2N
    srand(time(0));
    int define = b-a+1;
    for (int i = 0; i < N; i++)
    {
        int t = rand()%define;
        t += a;
        data.push_back(t);
    }
}

//输出数据
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

//输出错误信息
void Error(string s)
{
    cout<<s;
}

//复制数据
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
