//数据结构与算法分析C语言描述编程实践
//选择问题:从N个数中找出第k大的
#include <iostream>
#include "../../mylib/myclock.h"
#include "../../mylib/tool.h"
#include <vector>
#include <algorithm>

using namespace std;

//算法1：先对数据排序，再找出第k个数据。
template <typename T>
T Algorithm1(const vector<T> & data, const unsigned int k)
{
    if (k < 0 || k >= data.size())
    {
        return -1;
    }
    vector<T> tempData(data.size());
    tempData = data;
    sort(tempData.begin(), tempData.end());
    return tempData[k-1];
}

//算法2：先对头k个数排序，然后依次读入剩下的数，最后输出最后的数。
template <typename T>
T Algorithm2(const vector<T> & data, const unsigned int k)
{
    unsigned int N = data.size();
    if (k < 0 || k >= N)
    {
        return -1;
    }
    vector<T> tempData(k);
    for (unsigned int i = 0; i < k; i++)
    {
        tempData[i] = data[i];
    }
    sort(tempData.begin(), tempData.end());
    for (unsigned int j = k; j < N; j++)
    {
        //如果新读入的数据大于第k个数据，就不用再进行此次循环了。
        if (data[j] >= tempData[k-1])
        {
            continue;
        }
        for (unsigned int m = 0; m < k; m++)
        {
            //若读入的数据小于临时数组里的某个值，将临时数组中此值以后的每个值用前一值替代，再插入此值。
            if (data[j] < tempData[m])
            {
                for (unsigned int n = k-1; n > m; n--)
                {
                    tempData[n] = tempData[n-1];
                }
                tempData[m] = data[j];
                break;
            }
        }
    }
    return tempData[k-1];
}

int main()
{
    cout<<"输入数据规模:";
    int N, k;
    cin>>N;
    cout<<"输入k值:";
    cin>>k;
    if (N <= 0 || k < 0 || k >= N)
    {
        cout<<"输入错误，程序结束。"<<endl;
        return 0;
    }
    vector<int> data;
    GenerateData(data, N);

    MyClock mytim;
    //算法1
    mytim.begin();
    int res = Algorithm1(data, k);
    mytim.end();
    cout<<"算法1结果为:"<<res<<"，一共耗时:"<<mytim.GetHowLong()<<"秒"<<endl;

    //算法2
    mytim.begin();
    res = Algorithm2(data, k);
    mytim.end();
    cout<<"算法2结果为:"<<res<<"，一共耗时:"<<mytim.GetHowLong()<<"秒"<<endl;
    return 0;
}
