#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "../../mylib/tool.h"

using namespace std;

//练习3-2:给定两个链表L,P，按P的元素的值的顺序来输出L的内容。
void PrintLots(vector<int> L, vector<int> P)
{
    int N = L.size();
    for (int i = 0; i < N; i++)
    {
        cout<<L.at(P[i])<<" ";
    }
    cout<<endl;
}

void exec3_2(const int N)
{
    vector<int> L(N, 0), P(N, 0);
    GenerateData(L, N, 1, N);
    GenerateData(P, N, 1, N);
    cout<<"L:";
    DisplayData(L);
    cout<<endl<<"P:";
    DisplayData(P);
    cout<<endl;
    PrintLots(L, P);
}

//练习3-9：求2^4000内的0-9的数字分布，要用大数乘法了。
//计算a^n
vector<int> Multi(const int a, const int n)
{
    vector<int> result(1, 1);
    for (int i = 0; i < n; i++)
    {
        //用a乘每一位数
        for (unsigned int j = 0; j < result.size(); j++)
        {
            int temp = a*result[j];
            result[j] = temp;
        }
        //处理结果
        for (unsigned int j = 0; j < result.size()-1; j++)
        {
            if (result[j] >= 10)
            {
                result[j+1] += result[j]/10;
                result[j] = result[j] % 10;
            }
        }
        //处理最后一位的进位。
        int k = result.size();
        if (result[k-1] >= 10)
        {
            result.push_back(result[k-1]/10);
            result[k-1] = result[k-1] % 10;
        }
    }
    return result;
}

void exec3_9(const int a, const int n)
{
    vector<int> result = Multi(a, n);
    //数据处理
    int N = result.size();
    map<int, int> statics; //数据统计。
    //初始化
    for (int i = 0; i < 10; i++)
    {
        statics[i] = 0;
    }
    //累加
    for (int i = 0; i < N; i++)
    {
        statics[result[i]]++;
    }
    //计算结果并输出
    cout<<a<<"^"<<n<<"的结果共有"<<N<<"位"<<endl;
    cout<<"计算结果中0-9各个数字的分布频率为："<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<i<<":"<<double(statics[i])/double(N)<<endl;
    }
}

int main()
{
    cout<<"练习3_2:"<<endl;
    cout<<"输入数据规模 :";
    int N;
    cin>>N;
    exec3_2(N);
    cout<<"练习3_9:"<<endl;
    int a, n;
    cout<<"输入底数和指数:";
    cin>>a>>n;
    exec3_9(a, n);
    /*
    vector<int> result = Multi(2, 100);
    for (vector<int>::reverse_iterator i = result.rbegin(); i != result.rend(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    */
    return 0;
}
