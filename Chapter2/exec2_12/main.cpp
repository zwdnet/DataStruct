#include <iostream>
#include <vector>
#include "../../mylib/tool.h"

using namespace std;

//��ϰ2-12 ����С�����к͡�
template <typename T>
T MinSubSequence(const vector<T> & data)
{
    T thisMin = data[0];
    int i = 0;
    int N = data.size();
    for (i = 1; i < N; i++)
    {
        if (data[i] < thisMin)
        {
            thisMin = data[i];
        }
    }

    if (thisMin >= 0)
    {
        return thisMin;
    }

    T lineSum = 0;
    for (i = 0; i < N; i++)
    {
        lineSum += data[i];
        if (lineSum >0 && lineSum > thisMin)
        {
            lineSum = 0;
        }
        if (lineSum < thisMin)
        {
            thisMin = lineSum;
        }
    }
    return thisMin;
}

int main()
{
    cout << "�������ݹ�ģ��" << endl;
    int N;
    cin>>N;
    vector<int> data;
    GenerateData(data, N, -10, 10);
    cout<<"ԭʼ����Ϊ:";
    DisplayData(data);
    cout<<"��С�����к�Ϊ��"<<MinSubSequence(data)<<endl;
    return 0;
}
